#ifndef _xvGraph_H
#define _xvGraph_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#include "xvGlobalTable.h"
#include "xvNode.h"
#include "xvEdge.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

template <class TDelay>
class xvGraph : public xvNode<TDelay>,
                public xvEdge<TDelay> {
public :
        std::vector<xvNode<TDelay>*> xvGraphNodeList; 
        std::vector<xvEdge<TDelay>*> xvGraphEdgeList;

        std::vector<xvNode<TDelay>*> xvGraphVistList;

        std::vector<xvGraph<TDelay>*> xvPreGraphList;
        std::vector<xvGraph<TDelay>*> xvNxtGraphList;

        xvGraph(){ 
                    xvGraphNodeId =0; 
                    xvGraphEdgeId =0;
                    
                    xvGraphBgCycle =0;
                    xvGraphEdCycle =0;

                    xvDeep        =0;
 
                    typedef typename std::vector<xvNode<TDelay>*>::iterator xvGraphNode_iterator;
                    for(xvGraphNode_iterator NI = xvGraphNodeList.begin(),
                                             NE = xvGraphNodeList.end();   NI!=NE; NI++){ 
                        delete((*NI));   
                    }

                    typedef typename std::vector<xvEdge<TDelay>*>::iterator xvGraphEdge_iterator;
                    for(xvGraphEdge_iterator EI = xvGraphEdgeList.begin(),
                                             EE = xvGraphEdgeList.end();   EI!=EE; EI++){ 
                        delete((*EI));   
                    }

                    xvGraphNodeList.clear();
                    xvGraphEdgeList.clear();
                    xvGraphVistList.clear();

                    xvPreGraphList.clear();
                    xvNxtGraphList.clear();
                 }
               
 
        ~xvGraph(){
                    xvGraphNodeId =0;
                    xvGraphEdgeId =0;

                    xvGraphBgCycle =0;
                    xvGraphEdCycle =0;

                    xvDeep        =0;

                    typedef typename std::vector<xvNode<TDelay>*>::iterator xvGraphNode_iterator;
                    for(xvGraphNode_iterator NI = xvGraphNodeList.begin(),
                                             NE = xvGraphNodeList.end();   NI!=NE; NI++){ 
                        delete((*NI));   
                    }

                    typedef typename std::vector<xvEdge<TDelay>*>::iterator xvGraphEdge_iterator;
                    for(xvGraphEdge_iterator EI = xvGraphEdgeList.begin(),
                                             EE = xvGraphEdgeList.end();   EI!=EE; EI++){ 
                        delete((*EI));   
                    }

                    xvGraphNodeList.clear();
                    xvGraphEdgeList.clear();
                    xvGraphVistList.clear();

                    xvPreGraphList.clear();
                    xvNxtGraphList.clear();

                  }


        bool   xvSetNxtGraphList(xvGraph<TDelay> *ixvNxtGraph){ xvNxtGraphList.push_back(ixvNxtGraph); return true; }




        typedef typename std::vector<xvGraph<TDelay>*>::iterator xvNxtGraph_iterator;
        xvNxtGraph_iterator  xvNxtGraphBegin()  { return xvNxtGraphList.begin(); }
        xvNxtGraph_iterator  xvNxtGraphEnd()    { return xvNxtGraphList.end();   }

        int      xvNxtGraphSize()       { return xvNxtGraphList.size();  }
        bool     xvIsNxtGraphListEmpty(){ return xvNxtGraphList.empty(); }
                 
        std::vector<xvGraph<TDelay>*>  &xvGetNxtGraphLists(){ return xvNxtGraphList; }





        bool     xvReplaceNxtGraphList(xvGraph<TDelay> *ixvOrgNxtGraph, xvNode<TDelay> *ixvNewNxtGraph){ 
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvNxtGraphList.begin(), xvNxtGraphList.end(), ixvOrgNxtGraph);

                 if(I==xvNxtGraphList.end())
                   return false;

                 (*I) = static_cast<xvGraph<TDelay>*>(ixvNewNxtGraph);
 
        return true;
        }





        bool     xvDeleteNxtGraphList(xvGraph<TDelay> *ixvNxtGraph){
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvNxtGraphList.begin(), xvNxtGraphList.end(), ixvNxtGraph);

                 if(I==xvNxtGraphList.end())
                   return false;

                 xvNxtGraphList.erase(I);
 
        return true;
        }





        bool   xvSetPreGraphList(xvGraph<TDelay> *ixvPreGraph){ xvPreGraphList.push_back(ixvPreGraph); return true; }

        typedef typename std::vector<xvGraph<TDelay>*>::iterator xvPreGraph_iterator;
        xvPreGraph_iterator  xvPreGraphBegin()  { return xvPreGraphList.begin(); }
        xvPreGraph_iterator  xvPreGraphEnd()    { return xvPreGraphList.end();   }

        int      xvPreGraphSize()       { return xvPreGraphList.size();  }
        bool     xvIsPreGraphListEmpty(){ return xvPreGraphList.empty(); }
                 
        std::vector<xvGraph<TDelay>*>  &xvGetPreGraphLists(){ return xvPreGraphList; }





        bool     xvReplacePreGraphList(xvGraph<TDelay> *ixvOrgPreGraph, xvGraph<TDelay> *ixvNewPreGraph){ 
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvPreGraphList.begin(), xvPreGraphList.end(), ixvOrgPreGraph);

                 if(I==xvPreGraphList.end())
                   return false;

                 (*I) = static_cast<xvGraph<TDelay>*>(ixvNewPreGraph);
 
        return true;
        }





        bool     xvDeletePreGraphList(xvGraph<TDelay> *ixvPreGraph){
        typename std::vector<xvGraph<TDelay>*>::iterator I =
                 std::find(xvPreGraphList.begin(), xvPreGraphList.end(), ixvPreGraph);

                 if(I==xvPreGraphList.end())
                   return false;

                 xvPreGraphList.erase(I);
 
        return true;
        }




 
        void   xvSetGraphBgCycle(TDelay ixvGraphBgCycle){ xvGraphBgCycle = ixvGraphBgCycle; }
        TDelay xvGetGtaphBgCycle(){                      return          xvGraphBgCycle;  } 


        void   xvSetGraphEdCycle(TDelay ixvGraphEdCycle){ xvGraphEdCycle = ixvGraphEdCycle; }
        TDelay xvGetGtaphEdCycle(){                      return          xvGraphEdCycle;  } 



        xvEdge<TDelay> * xvSetGraphEdge(TDelay         ixvDelay,
                                        xvNode<TDelay> *ixvFromNodePtr,
                                        xvNode<TDelay> *ixvToNodePtr,
                                        xvEdgeType     ixvType,
                                        string         ixvName){

        xvEdge<TDelay> *xvEdgePtr = new xvEdge<TDelay>(ixvDelay,
                                                       ixvFromNodePtr,
                                                       ixvToNodePtr,
                                                       ixvType,
                                                       ixvName,
                                                       xvGraphEdgeId++);
        assert( xvEdgePtr!=NULL && "gen EdgePtr");

        return xvEdgePtr;
        }




        xvNode<TDelay> * xvSetGraphNode(TDelay     ixvDelay,
                                        xvNodeType ixvType,
                                        string     ixvName){

        xvNode<TDelay> *xvNodePtr = new xvNode<TDelay>(ixvDelay,
                                                       0,
                                                       0,
                                                       0,
                                                       0,
                                                       ixvType,
                                                       ixvName,
                                                       xvGraphNodeId++);
        assert( xvNodePtr!=NULL && "gen NodePtr");

        return xvNodePtr; 
        }

        // construct copy Node 2 Vist Graph
        bool xvCloneGraphNode2VistList(){
             xvGraphVistList = xvGraphNodeList; return true;
        }



        // construct copy Vist 2 Node Graph
        bool xvCloneGraphVist2NodeList(){
             xvGraphNodeList = xvGraphVistList; return true;
        }


        bool xvClearGraphVistList(){ xvGraphVistList.clear(); return true; } 
     

        bool xvIsGraphVistListExist(xvNode<TDelay> *ixvGraphNode){
             return  std::find(xvGraphVistList.begin(), xvGraphVistList.end(), ixvGraphNode) != xvGraphVistList.end();
        }



        bool xvSetGraphVistList(xvNode<TDelay> *ixvGraphNode){ xvGraphVistList.push_back(ixvGraphNode); return true; }




        
        bool xvDeleteGraphVistList(xvNode<TDelay> *ixvGraphNode){
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvGraphVistList.begin(), xvGraphVistList.end(), ixvGraphNode);
 
                 if(I==xvGraphVistList.end())
                   return false;

                 xvGraphVistList.erase(I);
        return true;
        }





        std::vector<xvNode<TDelay>*> &xvGetGraphVistLists(){ return xvGraphVistList; }

        bool xvIsGraphNodeListExist(string ixvNode){
             return std::find( (*xvGraphNodeList.begin())->xvGetName(), (*xvGraphNodeList.end())->xvGetName(), ixvNode) != xvGraphNodeList.end();
        }

        bool xvIsGraphNodeListExist(xvNode<TDelay> *ixvGraphNode){
             return  std::find(xvGraphNodeList.begin(), xvGraphNodeList.end(), ixvGraphNode) != xvGraphNodeList.end();
        }


        bool xvSetGraphNodeList(xvNode<TDelay> * ixvGraphNode){ xvGraphNodeList.push_back(ixvGraphNode); return true; }


        typedef typename std::vector<xvNode<TDelay>*>::iterator xvGraphNode_iterator;
        xvGraphNode_iterator  xvGraphNodeBegin()  { return xvGraphNodeList.begin(); }
        xvGraphNode_iterator  xvGraphNodeEnd()    { return xvGraphNodeList.end();   }

        int      xvGraphNodeSize()       { return xvGraphNodeList.size();  }
        bool     xvIsGraphNodeListEmpty(){ return xvGraphNodeList.empty(); }
 
        std::vector<xvNode<TDelay>*>  &xvGetGraphNodeLists(){ return xvGraphNodeList; }





        bool     xvReplaceGraphNodeList(xvNode<TDelay> *ixvOrgGraphNode, xvNode<TDelay> *ixvNewGraphNode){ 
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvGraphNodeList.begin(), xvGraphNodeList.end(), ixvOrgGraphNode);

                 if(I==xvGraphNodeList.end())
                   return false;

                 (*I) = static_cast<xvNode<TDelay>*>(ixvNewGraphNode);
 
        return true;
        }





        bool     xvDeleteGraphNodeList(xvNode<TDelay> *ixvGraphNode){
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvGraphNodeList.begin(), xvGraphNodeList.end(), ixvGraphNode);

                 if(I==xvGraphNodeList.end())
                   return false;

        typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
        // @ cut fan_in Nodes
        for(xvNode_iterator PI = (*I)->xvGetPreNodeLists().begin(),
                            PE = (*I)->xvGetPreNodeLists().end();   PI!=PE; ++PI){
           assert((*PI)!=NULL && "Cut_Fan_In_Nodes");
           (*PI)->xvDeleteNxtNodeList((*I));
        }
        // @ cut fan_out Nodes
        for(xvNode_iterator NI = (*I)->xvGetNxtNodeLists().begin(),
                            NE = (*I)->xvGetNxtNodeLists().end();   NI!=NE; ++NI){
           assert((*NI)!=NULL && "Cut_Fan_Out_Nodes");
           (*NI)->xvDeletePreNodeList((*I));
        }

        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
        // @ cut Edges
        for(xvEdge_iterator EI = xvGraphEdgeList.begin(),
                            EE = xvGraphEdgeList.end();   EI!=EE; ++EI){

            assert((*EI)!=NULL && "Cut_Edges");
            if( (*EI)->xvGetFromNodePtr() == (*I) ||
                (*EI)->xvGetToNodePtr()   == (*I) ){
                xvDeleteGraphEdgeList((*EI));
            }    
        }

        delete((*I));
        xvGraphNodeList.erase(I);
 
        return true;
        }





        bool xvIsGraphEdgeListExist(xvEdge<TDelay> *ixvGraphEdge){
             return  std::find(xvGraphEdgeList.begin(), xvGraphEdgeList.end(), ixvGraphEdge) != xvGraphEdgeList.end();
        }





        xvEdge<TDelay> * xvGetGraphEdgeListFmtoExist(xvNode<TDelay> *ixvFmGraphNode, xvNode<TDelay> *ixvToGraphNode, xvEdgeType ixvEdgeType){
        assert( ixvFmGraphNode != NULL && 
                ixvToGraphNode != NULL && "Get EdgeList From To");

//        cout << xvIsGraphNodeListExist(ixvToGraphNode) << endl;
//        cout << ixvFmGraphNode->xvGetName() << endl;
//        cout << ixvToGraphNode->xvGetName() << endl;
        
        assert( xvIsGraphNodeListExist(ixvFmGraphNode)!=false ||
                xvIsGraphNodeListExist(ixvToGraphNode)!=false && "Get EdgeList From To");

        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvGraphEdge_iterator;
 
        for(xvGraphEdge_iterator EI = xvGraphEdgeList.begin(),
                                 EE = xvGraphEdgeList.end();   EI!=EE; EI++){
 
            if( (static_cast<xvNode<TDelay>*>((*EI)->xvGetFromNodePtr()) == static_cast<xvNode<TDelay>*>(ixvFmGraphNode)) &&
                (static_cast<xvNode<TDelay>*>((*EI)->xvGetToNodePtr())   == static_cast<xvNode<TDelay>*>(ixvToGraphNode)) &&
                ((*EI)->xvGetType()                                      == ixvEdgeType)                                  ){
                return (*EI); 
             }
          }
          return NULL; 
        }





        bool xvSetGraphEdgeList(xvEdge<TDelay> * ixvGraphEdge){ xvGraphEdgeList.push_back(ixvGraphEdge); return true; }

        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvGraphEdge_iterator;
        xvGraphEdge_iterator  xvGraphEdgeBegin()  { return xvGraphEdgeList.begin(); }
        xvGraphEdge_iterator  xvGraphEdgeEnd()    { return xvGraphEdgeList.end();   }

        int      xvGraphEdgeSize()       { return xvGraphEdgeList.size();  }
        bool     xvIsGraphEdgeListEmpty(){ return xvGraphEdgeList.empty(); }

 
        std::vector<xvEdge<TDelay>*>  &xvGetGraphEdgeLists(){ return xvGraphEdgeList; }


        bool     xvReplaceGraphEdgeList(xvEdge<TDelay> *ixvOrgGraphEdge, xvNode<TDelay> *ixvNewGraphEdge){ 
        typename std::vector<xvEdge<TDelay>*>::iterator I =
                 std::find(xvGraphEdgeList.begin(), xvGraphEdgeList.end(), ixvOrgGraphEdge);

                 if(I==xvGraphEdgeList.end())
                   return false;

                 (*I) = static_cast<xvEdge<TDelay>*>(ixvNewGraphEdge);
 
        return true;
        }





        bool     xvDeleteGraphEdgeList(xvEdge<TDelay> *ixvGraphEdge){
        typename std::vector<xvEdge<TDelay>*>::iterator I =
                 std::find(xvGraphEdgeList.begin(), xvGraphEdgeList.end(), ixvGraphEdge);

                 if(I==xvGraphEdgeList.end())
                   return false;

                 delete((*I));
                 xvGraphEdgeList.erase(I);
 
        return true;
        }





        bool    xvDumpGraphEdgeList(){
        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;

        for(xvEdge_iterator I = xvGraphEdgeList.begin(), 
                            E = xvGraphEdgeList.end();   I!=E; ++I){

           cout << "EdgePtr     :: " << (*I)                     << endl;
           cout << "Delay       :: " << (*I)->xvGetDelay()       << endl;  
           cout << "FromNodePtr :: " << (*I)->xvGetFromNodePtr() << endl;
           cout << "ToNodePtr   :: " << (*I)->xvGetToNodePtr()   << endl;
           cout << "Type        :: " << (*I)->xvGetType()        << endl;
           cout << "Name        :: " << (*I)->xvGetName()        << endl;
           cout << "ID          :: " << (*I)->xvGetId()          << endl;  
           cout << endl;
           }

           cout << endl << endl << endl;
        return true;
        }





        bool    xvDumpGraphNodeList(){
        typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;

        for(xvNode_iterator I = xvGraphNodeList.begin(), 
                            E = xvGraphNodeList.end();   I!=E; ++I){

           cout << "NodePtr     :: " << (*I)                     << endl;
           cout << "Delay       :: " << (*I)->xvGetDelay()       << endl;  
           cout << "IncDelay    :: " << (*I)->xvGetIncDelay()    << endl;
           cout << "ASAPCycle   :: " << (*I)->xvGetASAPCycle()   << endl;
           cout << "ALAPCycle   :: " << (*I)->xvGetALAPCycle()   << endl;
           cout << "Cycle       :: " << (*I)->xvGetCycle()       << endl;
           cout << "Type        :: " << (*I)->xvGetType()        << endl;
           cout << "Name        :: " << (*I)->xvGetName()        << endl;
           cout << "ID          :: " << (*I)->xvGetId()          << endl;  
           
           for(xvNode_iterator NI = (*I)->xvGetNxtNodeLists().begin(),
                               NE = (*I)->xvGetNxtNodeLists().end();    NI!=NE; ++NI){  
           cout << "NxtNodePtr  :: " << (*NI) << endl;      
           }

           for(xvNode_iterator PI = (*I)->xvGetPreNodeLists().begin(),
                               PE = (*I)->xvGetPreNodeLists().end();    PI!=PE; ++PI){  
           cout << "PreNodePtr  :: " << (*PI) << endl;      
           }

           cout << endl;
         }

           cout << endl << endl << endl;
        return true;
        }





        // @ check Direct Edge
        bool   xvIsGraphDirectEdgePass(xvNode<TDelay> * ixvFmGraphNode,xvNode<TDelay> * ixvToGraphNode){
               assert( ixvFmGraphNode != NULL ||
                       ixvToGraphNode != NULL  && "DirectEdge Pass");
               
               assert( xvIsGraphNodeListExist(ixvFmGraphNode)!=false ||
                       xvIsGraphNodeListExist(ixvToGraphNode)!=false && "DirectEdge Pass");

        if( static_cast<xvNode<TDelay>*>(ixvFmGraphNode) == static_cast<xvNode<TDelay>*>(ixvToGraphNode) && xvDeep!=0 ){
            xvDeep =0;
            return true;
         }

         std::vector<xvNode<TDelay>*> xvNxtNodeLists = ixvFmGraphNode->xvGetNxtNodeLists();
         typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
 
         for(xvNode_iterator NI = xvNxtNodeLists.begin(),
                             NE = xvNxtNodeLists.end()    ; NI!=NE; ++NI){
               //Direct edge check
               if( xvGetGraphEdgeListFmtoExist( ixvFmGraphNode, (*NI), xvPointDirect )!=NULL ){
                   xvDeep++;
                   return xvIsGraphDirectEdgePass( (*NI), ixvToGraphNode);
              }
         }

        xvDeep =0;
        return false;
       }





        // @ check FeedBack Edge
        bool    xvIsGraphFeedBackEdgePass(xvNode<TDelay> * ixvFmGraphNode,xvNode<TDelay> * ixvToGraphNode){
                assert( ixvFmGraphNode != NULL ||
                        ixvToGraphNode != NULL && "FeedBackEdge Pass");   
           
                assert( xvIsGraphNodeListExist(ixvFmGraphNode)!=false ||
                        xvISGraphNodeListExist(ixvToGraphNode)!=false && "FeedBackEdge Pass");
 
         if( static_cast<xvNode<TDelay>*>(ixvFmGraphNode) == static_cast<xvNode<TDelay>*>(ixvToGraphNode) && xvDeep!=0){
             xvDeep =0;
             return true;
         }

         std::vector<xvNode<TDelay>*> xvPreNodeLists = ixvFmGraphNode->xvGetPreNodeLists();
         typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
 
         for(xvNode_iterator NI = xvPreNodeLists.begin(),
                             NE = xvPreNodeLists.end()    ; NI!=NE; ++NI){
               //FeedBack edge check
               if( xvGetGraphEdgeListFmtoExist( ixvFmGraphNode, (*NI), xvPointFeedBack )!=NULL ){
                   xvDeep++;
                   return xvIsGraphDirectEdgePass( (*NI), ixvToGraphNode);
              }
         }

        xvDeep =0;
        return false;
        }





        // @ check Direct Graph
        bool    xvIsDirectGraphPass(){
        if( xvIsGraphEdgeListEmpty() )
          return false;

        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
        for(xvEdge_iterator I = xvGraphEdgeList.begin(),
                            E = xvGraphEdgeList.end();   I!=E; ++I){          

             if((*I)->xvGetType()==xvPointFeedBack)
               return false;

             if( !xvIsGraphNodeListExist( (*I)->xvGetFromNodePtr() ) &&
                 !xvIsGraphNodeListExist( (*I)->xvGetToNodePtr()   ) )
                 return false;
        
          }
        return true;  
        }




//???
        bool    xvRunVerifyGraphPass(){

                if(xvIsDirectGraphPass())
                return true;


        }



        std::vector<xvNode<TDelay>*> &xvGetGraphUnConnectNodeLists(){

        xvClearGraphVistList();
        xvCloneGraphNode2VistList();

        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
        for(xvEdge_iterator I = xvGraphEdgeList.begin(),
                            E = xvGraphEdgeList.end();   I!=E; ++I){          

          xvDeleteGraphVistList( (*I)->xvGetFromNodePtr() );
          xvDeleteGraphVistList( (*I)->xvGetToNodePtr()   );
          }

         return xvGetGraphVistLists();
        }




        bool    xvIsVerifyGraphPass(){
        // @ Edges Check
        typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
        for(xvEdge_iterator EI = xvGraphEdgeList.begin(),
                            EE = xvGraphEdgeList.end();   EI!=EE; ++EI){          

           if( !xvIsGraphNodeListExist( (*EI)->xvGetFromNodePtr() ) ||
               !xvIsGraphNodeListExist( (*EI)->xvGetToNodePtr()   ) ){
               return false;
           }
         }
        
        // @ Nodes Check
        typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
        for(xvNode_iterator NI = xvGraphNodeList.begin(),
                            NE = xvGraphNodeList.end();   NI!=NE; ++NI){          

           if( !xvIsGraphNodeListExist((*NI)) ){
               return false;
           }
         }
      
        return true;      
        }




       std::vector<xvNode<TDelay>*>  &xvGetGraphInputLists(){

       xvClearGraphVistList();
       bool pass = true;

       typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
       for(xvEdge_iterator EI = xvGraphEdgeList.begin(),
                           EE = xvGraphEdgeList.end();   EI!=EE; ++EI){          

           assert( (*EI)->xvGetFromNodePtr()!=NULL  ||
                   (*EI)->xvGetToNodePtr()!=NULL    && " Get InputLists");

               if( xvIsGraphNodeListExist( (*EI)->xvGetFromNodePtr() )                &&
                   xvIsGraphNodeListExist( (*EI)->xvGetToNodePtr()   )                &&
                   (*EI)->xvGetType()                                == xvPointDirect ){
 
                  // @ without FeedBack edges && Direct edges
                  if( (*EI)->xvGetFromNodePtr()->xvIsPreNodeListEmpty() == true )
                      xvSetGraphVistList((*EI)->xvGetFromNodePtr());

                 // @ only 4 FeedBack edges 
                  else {
                      xvNode<TDelay> *IPtr = static_cast<xvNode<TDelay>*>((*EI)->xvGetFromNodePtr());
                      
                      typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
                      for(xvNode_iterator PI = IPtr->xvGetPreNodeLists().begin(),
                                          PE = IPtr->xvGetPreNodeLists().end();   PI!=PE; ++PI){
                                          assert((*PI)!=NULL && "Pre Nodes");

                        if( xvIsGraphDirectEdgePass( (*PI), IPtr ))
                             pass = false;
                      }
                       
                    if(pass==true)
                       xvSetGraphVistList(IPtr);
                  } 

               }
           }
          return xvGetGraphVistLists(); 
       }





       std::vector<xvNode<TDelay>*>  &xvGetGraphOutputLists(){

       xvClearGraphVistList();
       bool pass = true;

       typedef typename std::vector<xvEdge<TDelay>*>::iterator xvEdge_iterator;
       for(xvEdge_iterator EI = xvGraphEdgeList.begin(),
                           EE = xvGraphEdgeList.end();   EI!=EE; ++EI){          

           assert( (*EI)->xvGetFromNodePtr()!=NULL  ||
                   (*EI)->xvGetToNodePtr()!=NULL    && "Get OutputLists");

               if( xvIsGraphNodeListExist( (*EI)->xvGetFromNodePtr() )                &&
                   xvIsGraphNodeListExist( (*EI)->xvGetToNodePtr()   )                &&
                   (*EI)->xvGetType()                                == xvPointDirect ){
 
                   // @ without FeedBack edges &&  Direct edges
                   if( (*EI)->xvGetToNodePtr()->xvIsNxtNodeListEmpty() == true )
                       xvSetGraphVistList((*EI)->xvGetToNodePtr());    

                   // @  only 4 FeedBack edges
                   else {
                      xvNode<TDelay> *IPtr = static_cast<xvNode<TDelay>*>((*EI)->xvGetToNodePtr());
                      
                      typedef typename std::vector<xvNode<TDelay>*>::iterator xvNode_iterator;
                      for(xvNode_iterator PI = IPtr->xvGetNxtNodeLists().begin(),
                                          PE = IPtr->xvGetNxtNodeLists().end();   PI!=PE; ++PI){
                                          assert((*PI)!=NULL && "Nxt Nodes");

                         if( xvIsGraphDirectEdgePass( IPtr, (*PI) ))
                             pass = false;
                      }
                       
                    if(pass==true)
                       xvSetGraphVistList(IPtr);

                  }
     
              }
           }
          return xvGetGraphVistLists(); 
       }





      string test (){
         return "xvGraph";
       }


   private :
        int      xvGraphNodeId;
        int      xvGraphEdgeId;
        TDelay   xvGraphBgCycle;
        TDelay   xvGraphEdCycle;

        int      xvDeep;
  };
}

#endif 
