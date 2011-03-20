
#ifndef _xvNode_H
#define _xvNode_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#include "xvGlobalTable.h"

using namespace std;

namespace xVerilog {

template<class TDelay>
class xvNode {
public :
        std::vector<xvNode<TDelay>* > xvNxtNodeList;
        std::vector<xvNode<TDelay>* > xvPreNodeList;

        xvNode() { xvDelay    = 0;
                   xvIncDelay = 0;
                   xvASAPCycle= 0;
                   xvALAPCycle= 0;
                   xvCycle    = 0;
                   xvType     = xvLogicNop; 
                   xvName     = "";
                   xvId       = 0;
                   xvNxtNodeList.clear();
                   xvPreNodeList.clear();
                 }

        xvNode( TDelay     ixvDelay,
                TDelay     ixvIncDelay,
                int        ixvASAPCycle,
                int        ixvALAPCycle,
                int        ixvCycle,
                xvNodeType ixvType,
                string     ixvName,
                int        ixvId)    : xvDelay(ixvDelay),
                                       xvIncDelay(ixvIncDelay),
                                       xvASAPCycle(ixvASAPCycle),
                                       xvALAPCycle(ixvALAPCycle),
                                       xvCycle(ixvCycle),
                                       xvType(ixvType),
                                       xvName(ixvName),
                                       xvId(ixvId) {}                     
        ~xvNode() {
                    xvDelay    = 0;
                    xvIncDelay = 0;
                    xvASAPCycle= 0;
                    xvALAPCycle= 0;
                    xvCycle    = 0;
                    xvType     = xvLogicNop; 
                    xvName     = "";
                    xvId       = 0;
                    xvNxtNodeList.clear();  
                    xvPreNodeList.clear();
                  }


        void   xvSetDelay(TDelay ixvDelay){ xvDelay = ixvDelay; }
        TDelay xvGetDelay()               { return    xvDelay;  }

        void   xvSetIncDelay(TDelay ixvIncDelay){ xvIncDelay = ixvIncDelay; }
        TDelay xvGetIncDelay()                  { return    xvIncDelay;     }

        void   xvSetASAPCycle(int  ixvASAPCycle){ xvASAPCycle = ixvASAPCycle; }
        int    xvGetASAPCycle()                 { return    xvASAPCycle;      }

        void   xvSetALAPCycle(int  ixvALAPCycle){ xvALAPCycle = ixvALAPCycle; }
        int    xvGetALAPCycle()                 { return    xvALAPCycle;      }

        void   xvSetCycle(int  ixvCycle){ xvCycle = ixvCycle; }
        int    xvGetCycle()             { return    xvCycle;  }

        void       xvSetType(xvNodeType ixvType){ xvType = ixvType; }
        xvNodeType xvGetType()                  { return   xvType;  }

        void   xvSetName(string ixvName){ xvName  = ixvName;  }
        string xvGetName()              { return    xvName;   }

        void   xvSetId(int ixvId)       { xvId    = ixvId;    }
        int    xvGetId()                { return    xvId;     }

        bool   xvSetNxtNodeList(xvNode<TDelay> *ixvNxtNode){ xvNxtNodeList.push_back(ixvNxtNode); return true; }

        typedef typename std::vector<xvNode<TDelay>*>::iterator xvNxtNode_iterator;
        xvNxtNode_iterator  xvNxtNodeBegin()  { return xvNxtNodeList.begin(); }
        xvNxtNode_iterator  xvNxtNodeEnd()    { return xvNxtNodeList.end();   }

        int      xvNxtNodeSize()       { return xvNxtNodeList.size();  }
        bool     xvIsNxtNodeListEmpty(){ return xvNxtNodeList.empty(); }
                 
        std::vector<xvNode<TDelay>*>  &xvGetNxtNodeLists(){ return xvNxtNodeList; }

        bool     xvReplaceNxtNodeList(xvNode<TDelay> *ixvOrgNxtNode, xvNode<TDelay> *ixvNewNxtNode){ 
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvNxtNodeList.begin(), xvNxtNodeList.end(), ixvOrgNxtNode);

                 if(I==xvNxtNodeList.end())
                   return false;

                 (*I) = ixvNewNxtNode;
 
        return true;
        }

        bool     xvDeleteNxtNodeList(xvNode<TDelay> *ixvNxtNode){
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvNxtNodeList.begin(), xvNxtNodeList.end(), ixvNxtNode);

                 if(I==xvNxtNodeList.end())
                   return false;

                 xvNxtNodeList.erase(I);
 
        return true;
        }

        bool   xvSetPreNodeList(xvNode<TDelay> *ixvPreNode){ xvPreNodeList.push_back(ixvPreNode); return true; }

        typedef typename std::vector<xvNode<TDelay>*>::iterator xvPreNode_iterator;
        xvPreNode_iterator  xvPreNodeBegin()  { return xvPreNodeList.begin(); }
        xvPreNode_iterator  xvPreNodeEnd()    { return xvPreNodeList.end();   }

        int      xvPreNodeSize()       { return xvPreNodeList.size();  }
        bool     xvIsPreNodeListEmpty(){ return xvPreNodeList.empty(); }
                 
        std::vector<xvNode<TDelay>*>  &xvGetPreNodeLists(){ return xvPreNodeList; }

        bool     xvReplacePreNodeList(xvNode<TDelay> *ixvOrgPreNode, xvNode<TDelay> *ixvNewPreNode){ 
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvPreNodeList.begin(), xvPreNodeList.end(), ixvOrgPreNode);

                 if(I==xvPreNodeList.end())
                   return false;

                 (*I) = ixvNewPreNode;
 
        return true;
        }

        bool     xvDeletePreNodeList(xvNode<TDelay> *ixvPreNode){
        typename std::vector<xvNode<TDelay>*>::iterator I =
                 std::find(xvPreNodeList.begin(), xvPreNodeList.end(), ixvPreNode);

                 if(I==xvPreNodeList.end())
                   return false;

                 xvPreNodeList.erase(I);
 
        return true;
        }


        string test1() {
          return "xvNode";
        }

 private :
        TDelay     xvDelay;      //@Node Delay
        TDelay     xvIncDelay;   //@pass Dealy 
        int        xvASAPCycle;  
        int        xvALAPCycle;  
        int        xvCycle;
        xvNodeType xvType;
        string     xvName;
        int        xvId;
   };
}
#endif


