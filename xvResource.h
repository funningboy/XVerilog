#ifndef _xvResource_H
#define _xvResource_H

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

using namespace std;
using namespace xVerilog;

namespace xVerilog {

template <class TDelay>
class xvResource : public xvGraph<TDelay> {
      
public :
     std::vector<xvGraph<TDelay>*> xvResourceGraphList;

     std::vector<xvGraph<TDelay>*> xvResourceVistList;
      
      xvResource(){}
 
     ~xvResource(){} 
 };

} 
#endif
