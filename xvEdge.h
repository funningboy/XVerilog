#ifndef _xvEdge_H
#define _xvEdge_H

#include <iostream>
#include <string.h>

#include "xvGlobalTable.h"
#include "xvNode.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

template<class TDelay>
class xvEdge {
public :
        xvEdge() { xvDelay       = 0;
                   xvFromNodePtr = NULL;
                   xvToNodePtr   = NULL;
                   xvType        = xvPointNop;
                   xvName        = "";
                   xvId          = 0;                   
                 }

        xvEdge( TDelay         ixvDelay,
                xvNode<TDelay> *ixvFromNodePtr,
                xvNode<TDelay> *ixvToNodePtr,
                xvEdgeType     ixvType,
                string         ixvName,
                int            ixvId)    : xvDelay(ixvDelay),
                                           xvFromNodePtr(ixvFromNodePtr),
                                           xvToNodePtr(ixvToNodePtr),
                                          xvType(ixvType),
                                           xvName(ixvName),
                                           xvId(ixvId) {}                     
        ~xvEdge() {}

        void   xvSetDelay(TDelay ixvDelay){ xvDelay = ixvDelay; }
        TDelay xvGetDelay()               { return    xvDelay;  }

        void             xvSetFromNodePtr(xvNode<TDelay> *ixvFromNodePtr){ xvFromNodePtr = ixvFromNodePtr; }
        xvNode<TDelay> * xvGetFromNodePtr()                              { return          xvFromNodePtr;  }

        void             xvSetToNodePtr(xvNode<TDelay> *ixvToNodePtr){ xvToNodePtr = ixvToNodePtr; }
        xvNode<TDelay> * xvGetToNodePtr()                            { return        xvToNodePtr;  }

        void       xvSetType(xvEdgeType ixvType){ xvType = ixvType; }
        xvEdgeType xvGetType()                  { return   xvType;  }

        void   xvSetName(string ixvName){ xvName  = ixvName;  }
        string xvGetName()              { return    xvName;   }

        void   xvSetId(int ixvId)       { xvId    = ixvId;    }
        int    xvGetId()                { return    xvId;     }

private :
        TDelay           xvDelay;
        xvNode<TDelay> * xvFromNodePtr;
        xvNode<TDelay> * xvToNodePtr;
        xvEdgeType       xvType;
        string           xvName;
        int              xvId;
   };
}
#endif


