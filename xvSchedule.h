#ifndef _xvSchedule_H
#define _xvSchedule_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include "xvGlobalTable.h"
#include "xvNode.h"
#include "xvEdge.h"
#include "xvGraph.h"
#include "xvCalculate.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

template <class TDelay>
class xvSchedule : public xvGraph<TDelay> {
      
public :
     std::vector<xvGraph<TDelay>*> xvScheduleGraphList;

     std::vector<xvGraph<TDelay>*> xvScheduleVistList;

     xvCalculate<TDelay> *xvCalPtr;
      
      xvSchedule(){
                    xvScheduleTmpId =0;

                    xvScheduleGraphList.clear();
                    xvScheduleVistList.clear();
                  }

     ~xvSchedule(){
                    xvScheduleTmpId =0;

                    xvScheduleGraphList.clear();
                    xvScheduleVistList.clear();
                  }


        bool xvClearScheduleVistList(){  xvScheduleVistList.clear(); }

        bool xvCloneScheduleGraph2VistList(){ 
             xvScheduleVistList = xvScheduleGraphList; return true;
        } 

        bool xvCloneScheduleVist2GraphList(){
             xvScheduleGraphList = xvScheduleVistList; return true;
        }


        bool xvIsScheduleVistListExist(xvGraph<TDelay> *ixvScheduleGraph){
             return  std::find(xvScheduleVistList.begin(), xvScheduleVistList.end(), ixvScheduleGraph) != xvScheduleVistList.end();
        }


        bool xvSetScheduleVistList(xvGraph<TDelay> * ixvScheduleGraph){ xvScheduleVistList.push_back(ixvScheduleGraph); return true; }

     
        xvGraph<TDelay> * xvPopBackScheduleVistList(){ return xvScheduleVistList.pop_back(); }


        typedef typename std::vector<xvGraph<TDelay>*>::iterator xvScheduleVist_iterator;
        xvScheduleVist_iterator  xvScheduleVistBegin()  { return xvScheduleVistList.begin(); }
        xvScheduleVist_iterator  xvScheduleVistEnd()    { return xvScheduleVistList.end();   }

        int      xvScheduleVistSize()       { return xvScheduleVistList.size();  }
        bool     xvIsScheduleVistListEmpty(){ return xvScheduleVistList.empty(); }
 
        std::vector<xvGraph<TDelay>*>  &xvGetScheduleVistLists(){ return xvScheduleVistList; }





        bool     xvReplaceScheduleVistList(xvGraph<TDelay> *ixvOrgScheduleGraph, xvGraph<TDelay> *ixvNewScheduleGraph){ 
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvScheduleVistList.begin(), xvScheduleVistList.end(), ixvOrgScheduleGraph);

                 if(I==xvScheduleVistList.end())
                   return false;

                 (*I) = static_cast<xvGraph<TDelay>*>(ixvNewScheduleGraph);
 
        return true;
        }





        bool     xvDeleteScheduleVistList(xvGraph<TDelay> *ixvScheduleGraph){
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvScheduleVistList.begin(), xvScheduleVistList.end(), ixvScheduleGraph);

                 if(I==xvScheduleVistList.end())
                   return false;
               
                 delete((*I));
                 xvScheduleVistList.erase(I);

       return true;
       }




        bool xvIsScheduleGraphListExist(xvGraph<TDelay> *ixvScheduleGraph){
             return  std::find(xvScheduleGraphList.begin(), xvScheduleGraphList.end(), ixvScheduleGraph) != xvScheduleGraphList.end();
        }


        bool xvSetScheduleGraphList(xvGraph<TDelay> * ixvScheduleGraph){ xvScheduleGraphList.push_back(ixvScheduleGraph); return true; }


        typedef typename std::vector<xvGraph<TDelay>*>::iterator xvScheduleGraph_iterator;
        xvScheduleGraph_iterator  xvScheduleGraphBegin()  { return xvScheduleGraphList.begin(); }
        xvScheduleGraph_iterator  xvScheduleGraphEnd()    { return xvScheduleGraphList.end();   }

        int      xvScheduleGraphSize()       { return xvScheduleGraphList.size();  }
        bool     xvIsScheduleGraphListEmpty(){ return xvScheduleGraphList.empty(); }
 
        std::vector<xvGraph<TDelay>*>  &xvGetScheduleGraphLists(){ return xvScheduleGraphList; }





        bool     xvReplaceScheduleGraphList(xvGraph<TDelay> *ixvOrgScheduleGraph, xvGraph<TDelay> *ixvNewScheduleGraph){ 
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvScheduleGraphList.begin(), xvScheduleGraphList.end(), ixvOrgScheduleGraph);

                 if(I==xvScheduleGraphList.end())
                   return false;

                 (*I) = ixvNewScheduleGraph;
 
        return true;
        }





        bool     xvDeleteScheduleGraphList(xvGraph<TDelay> *ixvScheduleGraph){
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvScheduleGraphList.begin(), xvScheduleGraphList.end(), ixvScheduleGraph);

                 if(I==xvScheduleGraphList.end())
                   return false;
               
                 delete((*I));
                 xvScheduleGraphList.erase(I);

       return true;
       }





      bool      xvRunBFSDirectSchedulePass(){


      }





     

      bool      xvSetGraphDirectTmpRegFmTo(xvNode<TDelay> * ixvFmNode, xvNode<TDelay> * ixvToNode, xvGraph<TDelay> * ixvGraph){

                assert( ixvFmNode!=NULL ||
                        ixvToNode!=NULL ||
                        ixvGraph !=NULL && "Set DirectTmpRegFmTo");

                assert( ixvGraph->xvIsGraphNodeListExist(ixvFmNode)!=false ||
                        ixvGraph->xvIsGraphNodeListExist(ixvToNode)!=false && "Set DirectTmpRegFmTo");

               xvEdge<TDelay> *xvEdgePtr = static_cast<xvEdge<TDelay>*>(ixvGraph->xvGetGraphEdgeListFmtoExist(ixvFmNode, ixvToNode, xvPointDirect) );
               assert( xvEdgePtr!=NULL && "Set DirectTmpRegFmTo");

               //cut Edge
               ixvGraph->xvDeleteGraphEdgeList(xvEdgePtr);

               // @ Write Reg
               xvNode<TDelay> *xvNodeRegWritePtr = static_cast<xvNode<TDelay>*>(ixvGraph->xvSetGraphNode(RegWriteDelay, xvLogicRegWrite, "_N_SCHE_"));
               assert( xvNodeRegWritePtr!=NULL && "Set DirectTmpRegFmTo");
               ixvGraph->xvSetGraphNodeList(xvNodeRegWritePtr); 

               xvNodeRegWritePtr->xvSetPreNodeList(ixvFmNode);
               ixvFmNode->xvSetNxtNodeList(xvNodeRegWritePtr);

               // @ Edge
               xvEdge<TDelay> *xvEdgeFm2RegWritePtr = static_cast<xvEdge<TDelay>*>(ixvGraph->xvSetGraphEdge(0, ixvFmNode, xvNodeRegWritePtr,
                                                                                   xvPointDirect, "_W_SCHE_"));
               assert( xvEdgeFm2RegWritePtr!=NULL && "Set DirectTmpRegFmTo");
               ixvGraph->xvSetGraphEdgeList(xvEdgeFm2RegWritePtr);
   
               // @ Read Reg
               xvNode<TDelay> *xvNodeRegReadPtr = static_cast<xvNode<TDelay>*>(ixvGraph->xvSetGraphNode(RegReadDelay, xvLogicRegRead, "_N_SCHE_"));
               assert( xvNodeRegReadPtr!=NULL && "Set DirectTmpRegFmTo");
               ixvGraph->xvSetGraphNodeList(xvNodeRegReadPtr);

               // @ Edge 
               xvEdge<TDelay> *xvEdgeRegWrite2ReadPtr = static_cast<xvEdge<TDelay>*>(ixvGraph->xvSetGraphEdge(0, xvNodeRegWritePtr, xvNodeRegReadPtr,
                                                                                     xvPointDirect, "_W_SCHE_"));
               assert( xvEdgeRegWrite2ReadPtr!=NULL && "Set DirectTmpRegFmTo");
               ixvGraph->xvSetGraphEdgeList(xvEdgeRegWrite2ReadPtr);
 
               xvNodeRegReadPtr->xvSetPreNodeList(xvNodeRegWritePtr);
               xvNodeRegWritePtr->xvSetNxtNodeList(xvNodeRegReadPtr);

               // @ Edge 
               xvEdge<TDelay> *xvEdgeRegReadPtr = static_cast<xvEdge<TDelay>*>(ixvGraph->xvSetGraphEdge(0, xvNodeRegWritePtr, xvNodeRegReadPtr,
                                                                               xvPointDirect, "_W_SCHE_"));
               assert( xvEdgeRegReadPtr!=NULL && "Set DirectTmpRegFmTo");
               ixvGraph->xvSetGraphEdgeList(xvEdgeRegReadPtr);

               ixvToNode->xvSetPreNodeList(xvNodeRegReadPtr);
               xvNodeRegReadPtr->xvSetNxtNodeList(ixvToNode);

       return true;
    }








      bool      xvRunCycleSchedulePass(){
 
      xvClearScheduleVistList();
      xvCloneScheduleGraph2VistList();

      typedef typename std::vector<xvGraph<TDelay>*>::iterator xvScheduleVist_iterator;
      for(xvScheduleVist_iterator SI = xvScheduleVistList.begin(), 
                                  SE = xvScheduleVistList.end();   SI!=SE; ++SI){

         xvGraph<TDelay> *xvGraphPtr = static_cast<xvGraph<TDelay>*>((*SI));
         assert( xvGraphPtr!=NULL && "Run Cycle");

         assert ( xvGraphPtr->xvIsDirectGraphPass()!=false ||
                  xvGraphPtr->xvIsVerifyGraphPass()!=false && "Run Cycle");

              std::vector<xvNode<TDelay>*> InputLists = xvGraphPtr->xvGetGraphInputLists();                           
              std::vector<xvNode<TDelay>*> VistLists;
              VistLists.clear();
 
           typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;

          while(true){
             for(xvNode_iterator I = InputLists.begin(),
                                 E = InputLists.end();    I!=E; ++I){

                 xvNode<TDelay> *xvNodePtr = static_cast<xvNode<TDelay>*>(*I);
                 assert( xvNodePtr!=NULL ||
                         xvGraphPtr->xvIsGraphNodeListExist(xvNodePtr)!=false && "Run Cycle");

                    std::vector<xvNode<TDelay>*> PreNodeLists = xvNodePtr->xvGetPreNodeLists();
                    for(xvNode_iterator NI = PreNodeLists.begin(),
                                        NE = PreNodeLists.end();   NI!=NE; ++NI){

                     xvNode<TDelay> *xvFmNodePtr = static_cast<xvNode<TDelay>*>(*NI);
 
                     xvEdge<TDelay> *xvEdgePtr = static_cast<xvEdge<TDelay>*>(xvGraphPtr->xvGetGraphEdgeListFmtoExist( xvFmNodePtr, xvNodePtr, xvPointDirect ));
                            // @ check already cut Edge
                            if( xvEdgePtr!=NULL ){
                            TDelay  IncDelay   = xvFmNodePtr->xvGetIncDelay() + xvEdgePtr->xvGetDelay() + xvNodePtr->xvGetDelay(); 

                            if( xvNodePtr->xvGetType() == xvLogicRegRead ||
                                xvNodePtr->xvGetType() == xvLogicRegWrite ){
                                xvNodePtr->xvSetIncDelay(0);
     
                           // @ xvLogicOp[ADD,MUL...]
                           } else {
                             if(IncDelay > 1){
                                 xvSetGraphDirectTmpRegFmTo( xvFmNodePtr, xvNodePtr, xvGraphPtr);
                                 xvNodePtr->xvSetIncDelay( xvNodePtr->xvGetDelay() );
                             } else {
                                 xvNodePtr->xvSetIncDelay(IncDelay);
                             }
                           }                                                   
                        }
                      }
                std::vector<xvNode<TDelay>*> NxtNodeLists = xvNodePtr->xvGetNxtNodeLists();
                for(xvNode_iterator NI = NxtNodeLists.begin(),
                                    NE = NxtNodeLists.end();   NI!=NE; ++NI){
                    VistLists.push_back( (*NI) ); 
                }
             }

            if( !VistLists.empty() ){
                InputLists.clear(); 
                InputLists = VistLists; 
                VistLists.clear();
            } else {
                 break;
            }
          }
                  
       }

      xvCloneScheduleVist2GraphList();
      xvClearScheduleVistList();
 
      return true;
      }







      bool      xvRunASAPSchedulePass(){
 
      xvClearScheduleVistList();
      xvCloneScheduleGraph2VistList();

      typedef typename std::vector<xvGraph<TDelay>*>::iterator xvScheduleVist_iterator;
      for(xvScheduleVist_iterator SI = xvScheduleVistList.begin(), 
                                  SE = xvScheduleVistList.end();   SI!=SE; ++SI){

         xvGraph<TDelay> *xvGraphPtr = static_cast<xvGraph<TDelay>*>((*SI));
         assert( xvGraphPtr!=NULL && "Run ASAP");

         assert ( xvGraphPtr->xvIsDirectGraphPass()!=false ||
                  xvGraphPtr->xvIsVerifyGraphPass()!=false && "Run ASAP");

              std::vector<xvNode<TDelay>*> InputLists = xvGraphPtr->xvGetGraphInputLists();                           
              std::vector<xvNode<TDelay>*> VistLists;
              VistLists.clear();
 
           typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;

          while(true){
             for(xvNode_iterator I = InputLists.begin(),
                                 E = InputLists.end();    I!=E; ++I){

                 xvNode<TDelay> *xvNodePtr = static_cast<xvNode<TDelay>*>(*I);
                 assert( xvNodePtr!=NULL ||
                         xvGraphPtr->xvIsGraphNodeListExist(xvNodePtr)!=false && "Run ASAP");

                    int  MaxCycle =0;
                    std::vector<xvNode<TDelay>*> PreNodeLists = xvNodePtr->xvGetPreNodeLists();
                    for(xvNode_iterator NI = PreNodeLists.begin(),
                                        NE = PreNodeLists.end();   NI!=NE; ++NI){

                     xvNode<TDelay> *xvFmNodePtr = static_cast<xvNode<TDelay>*>(*NI);
 
                            MaxCycle = ( xvFmNodePtr->xvGetASAPCycle() > MaxCycle )? xvFmNodePtr->xvGetASAPCycle() : MaxCycle; 
                    }
                            xvNodePtr->xvSetASAPCycle(MaxCycle);

                            if( xvNodePtr->xvGetType() == xvLogicRegRead ) 
                                xvNodePtr->xvSetASAPCycle( MaxCycle+1 );
                                                                     
                std::vector<xvNode<TDelay>*> NxtNodeLists = xvNodePtr->xvGetNxtNodeLists();
                for(xvNode_iterator NI = NxtNodeLists.begin(),
                                    NE = NxtNodeLists.end();   NI!=NE; ++NI){
                    VistLists.push_back( (*NI) ); 
                }
             }

            if( !VistLists.empty() ){
                InputLists.clear(); 
                InputLists = VistLists; 
                VistLists.clear();
            } else {
                 break;
            }
          }
                  
       }

      xvCloneScheduleVist2GraphList();
      xvClearScheduleVistList();
 
      return true;
      }






      bool      xvRunALAPSchedulePass(){
 
      xvClearScheduleVistList();
      xvCloneScheduleGraph2VistList();

      typedef typename std::vector<xvGraph<TDelay>*>::iterator xvScheduleVist_iterator;
      for(xvScheduleVist_iterator SI = xvScheduleVistList.begin(), 
                                  SE = xvScheduleVistList.end();   SI!=SE; ++SI){

         xvGraph<TDelay> *xvGraphPtr = static_cast<xvGraph<TDelay>*>((*SI));
         assert( xvGraphPtr!=NULL && "Run ALAP");

         assert ( xvGraphPtr->xvIsDirectGraphPass()!=false ||
                  xvGraphPtr->xvIsVerifyGraphPass()!=false && "Run ALAP");

              std::vector<xvNode<TDelay>*> OutputLists = xvGraphPtr->xvGetGraphOutputLists();                           
              std::vector<xvNode<TDelay>*> VistLists;
              VistLists.clear();
 
           typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;

          while(true){
             for(xvNode_iterator I = OutputLists.begin(),
                                 E = OutputLists.end();    I!=E; ++I){

                 xvNode<TDelay> *xvNodePtr = static_cast<xvNode<TDelay>*>(*I);
                 assert( xvNodePtr!=NULL ||
                         xvGraphPtr->xvIsGraphNodeListExist(xvNodePtr)!=false && "Run ALAP");

                    std::vector<xvNode<TDelay>*> NxtNodeLists = xvNodePtr->xvGetNxtNodeLists();
                    if( NxtNodeLists.empty() )
                        xvNodePtr->xvSetALAPCycle( xvNodePtr->xvGetASAPCycle() );

                    for(xvNode_iterator NI = NxtNodeLists.begin(),
                                        NE = NxtNodeLists.end();   NI!=NE; ++NI){

                     xvNode<TDelay> *xvToNodePtr = static_cast<xvNode<TDelay>*>(*NI);

                                xvNodePtr->xvSetALAPCycle( xvToNodePtr->xvGetALAPCycle() );                               

                            if( xvNodePtr->xvGetType() == xvLogicRegWrite ) 
                                xvNodePtr->xvSetALAPCycle( xvToNodePtr->xvGetALAPCycle()-1 );
                           
                    }

                std::vector<xvNode<TDelay>*> PreNodeLists = xvNodePtr->xvGetPreNodeLists();
                for(xvNode_iterator PI = PreNodeLists.begin(),
                                    PE = PreNodeLists.end();   PI!=PE; ++PI){
                    VistLists.push_back( (*PI) ); 
                }
             }

            if( !VistLists.empty() ){
                OutputLists.clear(); 
                OutputLists = VistLists; 
                VistLists.clear();
            } else {
                 break;
            }
          }
                  
       }

      xvCloneScheduleVist2GraphList();
      xvClearScheduleVistList();
 
      return true;
      }



private :       
      int xvScheduleTmpId;

      TDelay RegReadDelay;
      TDelay RegWriteDelay;
 
};

}
#endif
