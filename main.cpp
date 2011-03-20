

#include <iostream>
#include <assert.h>
#include <exception>

#include "xvGlobalTable.h"
#include "xvGraph.h"
#include "xvNode.h"
#include "xvEdge.h"
#include "xvSchedule.h"
#include "xvCalculate.h"

using namespace std;
using namespace xVerilog;

int main(int argc, char **argv){


      // @ example d=(a+b)*c; 
      xvCalculate<DefTDelay> *xvCalPtr = new xvCalculate<DefTDelay>();
                       assert(xvCalPtr!=NULL && "xvCalPtr == NULL");

      assert( xvCalPtr->xvCalculateVerifyPass()!=false && "cycle constrain fail");

      xvGraph<DefTDelay> *xvGraphPtr = new xvGraph<DefTDelay>();
                    assert(xvGraphPtr!=NULL && "xvGrapPtr == NULL");

      // @ a LHS
      DefTDelay a_LHS_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicRegRead);
      xvNode<DefTDelay>  *xvNodePtr_a  = xvGraphPtr->xvSetGraphNode(a_LHS_Delay,xvLogicRegRead,"a");
                   assert(xvNodePtr_a!=NULL && "xvNodePtr_a == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_a);
          
      // @ b RHS
      DefTDelay b_RHS_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicRegRead);
      xvNode<DefTDelay>  *xvNodePtr_b  = xvGraphPtr->xvSetGraphNode(b_RHS_Delay,xvLogicRegRead,"b");
                   assert(xvNodePtr_b!=NULL && "xvNodePtr_b == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_b);
 
      // @ + operator RHS
      DefTDelay o_ADD_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicOpADD);
      xvNode<DefTDelay>  *xvNodePtr_ADD  = xvGraphPtr->xvSetGraphNode(o_ADD_Delay,xvLogicOpADD,"Add");
                   assert(xvNodePtr_ADD!=NULL && "xvNodePtr_o == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_ADD);

      // @ Edge a -> + 
      xvEdge<DefTDelay> *xvEdgePtr_a_2_ADD = xvGraphPtr->xvSetGraphEdge(0,xvNodePtr_a,xvNodePtr_ADD,xvPointDirect,"w1");
                   assert(xvEdgePtr_a_2_ADD!=NULL && "xvEdgePtr_a_2_o == NULL");
                       xvGraphPtr->xvSetGraphEdgeList(xvEdgePtr_a_2_ADD);

      // @ a NxtNodeList
                  xvNodePtr_a->xvSetNxtNodeList(xvNodePtr_ADD);
      // @ + PreNodeList
                  xvNodePtr_ADD->xvSetPreNodeList(xvNodePtr_a);

      // @ Edge b -> +
      xvEdge<DefTDelay> *xvEdgePtr_b_2_ADD = xvGraphPtr->xvSetGraphEdge(0,xvNodePtr_b,xvNodePtr_ADD,xvPointDirect,"w2");
                   assert(xvEdgePtr_b_2_ADD!=NULL && "xvEdgePtr_b_2_o == NULL");
                       xvGraphPtr->xvSetGraphEdgeList(xvEdgePtr_b_2_ADD);

      // @ b NxtNodeList
                  xvNodePtr_b->xvSetNxtNodeList(xvNodePtr_ADD);
      // @ + PreNodeList
                  xvNodePtr_ADD->xvSetPreNodeList(xvNodePtr_b);

     // @ * Operator  
      DefTDelay o_MUL_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicOpMUL);
      xvNode<DefTDelay>  *xvNodePtr_MUL  = xvGraphPtr->xvSetGraphNode(o_MUL_Delay,xvLogicOpMUL,"MUL");
                   assert(xvNodePtr_MUL!=NULL && "xvNodePtr_o == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_MUL);

       // @ c LHS  + RHS 
      DefTDelay c_LHS_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicRegRead);
      xvNode<DefTDelay>  *xvNodePtr_c  = xvGraphPtr->xvSetGraphNode(c_LHS_Delay,xvLogicRegRead,"c");
                   assert(xvNodePtr_c!=NULL && "xvNodePtr_c == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_c);

       // @ Edge + -> *
       xvEdge<DefTDelay> *xvEdgePtr_ADD_2_MUL = xvGraphPtr->xvSetGraphEdge(0,xvNodePtr_ADD,xvNodePtr_MUL,xvPointDirect,"w3");
                   assert(xvEdgePtr_ADD_2_MUL!=NULL && "xvEdgePtr_ADD_2_MUL == NULL");
                      xvGraphPtr->xvSetGraphEdgeList(xvEdgePtr_ADD_2_MUL);
  
       // @ + NxtNodeList 
                 xvNodePtr_ADD->xvSetNxtNodeList(xvNodePtr_MUL);
       // @ * PreNodeList
                 xvNodePtr_MUL->xvSetPreNodeList(xvNodePtr_ADD);

       // @ Edge c -> *
       xvEdge<DefTDelay> *xvEdgePtr_c_2_MUL = xvGraphPtr->xvSetGraphEdge(0,xvNodePtr_c,xvNodePtr_MUL,xvPointDirect,"w4");
                   assert(xvEdgePtr_c_2_MUL!=NULL && "xvEdgePtr_c_2_MUL == NULL");
                      xvGraphPtr->xvSetGraphEdgeList(xvEdgePtr_c_2_MUL);

       // @ c NxtNodeList 
                 xvNodePtr_c->xvSetNxtNodeList(xvNodePtr_MUL);
       // @ * PreNodeList
                 xvNodePtr_MUL->xvSetPreNodeList(xvNodePtr_c);

      // @ d
      DefTDelay d_RST_Delay = xvCalPtr->xvGetFastNodeDelay(xvLogicRegWrite);
      xvNode<DefTDelay>  *xvNodePtr_d  = xvGraphPtr->xvSetGraphNode(d_RST_Delay,xvLogicRegWrite,"d");
                   assert(xvNodePtr_d!=NULL && "xvNodePtr_d == NULL");
                       xvGraphPtr->xvSetGraphNodeList(xvNodePtr_d);

       // @ Edge * -> d
       xvEdge<DefTDelay> *xvEdgePtr_MUL_2_d = xvGraphPtr->xvSetGraphEdge(0,xvNodePtr_MUL,xvNodePtr_d,xvPointDirect,"w5");
                   assert(xvEdgePtr_MUL_2_d!=NULL && "xvEdgePtr_MUL_2_d == NULL");
                     xvGraphPtr->xvSetGraphEdgeList(xvEdgePtr_MUL_2_d);

       // @ * NxtNodeList 
                 xvNodePtr_MUL->xvSetNxtNodeList(xvNodePtr_d);
       // @ d PreNodeList
                 xvNodePtr_d->xvSetPreNodeList(xvNodePtr_MUL);


      // @ sample test 4 cut  xvNode     
      xvGraphPtr->xvDumpGraphEdgeList();
      xvGraphPtr->xvDumpGraphNodeList();

//      xvGraphPtr->xvDeleteGraphNodeList(xvNodePtr_ADD);
//      cout << xvGraphPtr->xvIsVerifyGraphPass() << endl;
 
//      cout << xvGraphPtr->xvIsGraphDirectEdgePass(xvNodePtr_MUL,xvNodePtr_d) << endl;
//      cout << xvGraphPtr->xvIsGraphDirectEdgePass(xvNodePtr_MUL,xvNodePtr_d) << endl;


//      cout << xvGraphPtr->xvIsGraphDirectEdgePass(xvNodePtr_c,xvNodePtr_c) << endl;
//      cout << xvGraphPtr->xvIsGraphDirectEdgePass(xvNodePtr_c,xvNodePtr_a) << endl;

//      std::vector<xvNode<DefTDelay>*> unConnectLists = xvGraphPtr->xvGetGraphUnConnectNodeLists();


//      xvGraphPtr->xvDumpGraphEdgeList();
//      xvGraphPtr->xvDumpGraphNodeList();
                
      xvSchedule<DefTDelay> *xvSchedulePtr = new xvSchedule<DefTDelay>();
      xvSchedulePtr->xvSetScheduleGraphList(xvGraphPtr);
      xvSchedulePtr->xvRunCycleSchedulePass();
      xvSchedulePtr->xvRunASAPSchedulePass();
      xvSchedulePtr->xvRunALAPSchedulePass();

      xvGraphPtr->xvDumpGraphEdgeList();
      xvGraphPtr->xvDumpGraphNodeList();
 
                  
      delete(xvSchedulePtr);
      delete(xvGraphPtr);

return 0;


}
