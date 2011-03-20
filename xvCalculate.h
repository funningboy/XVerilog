#ifndef _xvCalculate_H
#define _xvCalculate_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#include "xvGlobalTable.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

template <class TDelay>
class xvCalculate {

public :

      xvCalculate(){}

     ~xvCalculate(){}

         bool   xvIsRegNodeType(xvNodeType ixvNodeType){

            xvNodeType RegNodeList[] = { xvLogicRegRead,
                                         xvLogicRegWrite };

          for(int i=1; i<= sizeof(RegNodeList)/sizeof(RegNodeList[0]); i++){
              if(ixvNodeType == RegNodeList[i])
                 return true;

            }
            
          return false;
         }



         bool   xvIsOperatorNodeType(xvNodeType ixvNodeType){

            xvNodeType OpNodeList[] = { xvLogicOpADD, 
                                        xvLogicOpSUB,    
                                        xvLogicOpMUL,    
                                        xvLogicOpDIV,    
                                        xvLogicOpRSHF,   
                                        xvLogicOpLSHF,   
                                        xvLogicOpCMP,    
                                        xvLogicOpAND,    
                                        xvLogicOpOR };  
 
          for(int i=1; i<= sizeof(OpNodeList)/sizeof(OpNodeList[0]); i++){
              if(ixvNodeType == OpNodeList[i])
                 return true;

            }
            
          return false;
         }

         TDelay xvGetMaxFastOperatorNodeDelay(){

            TDelay FastOpNodeList[] = { xvDelayFastOpADD, 
                                        xvDelayFastOpSUB,    
                                        xvDelayFastOpMUL,    
                                        xvDelayFastOpDIV,    
                                        xvDelayFastOpRSHF,   
                                        xvDelayFastOpLSHF,   
                                        xvDelayFastOpCMP,    
                                        xvDelayFastOpAND,    
                                        xvDelayFastOpOR };  
   
            TDelay Max = FastOpNodeList[0];

            for(int i=1; i<= sizeof(FastOpNodeList)/sizeof(FastOpNodeList[0]); i++){
               Max = ( FastOpNodeList[i] > Max)? FastOpNodeList[i] : Max;
            }
            
          return Max;
         }



         bool   xvCalculateVerifyPass(){

         TDelay Cycle = xvGetMaxFastOperatorNodeDelay() + 
                        xvDelayFastRegRead              +
                        xvDelayFastRegWrite;

                //@ 1 cycle constrain
                if(Cycle>1) 
                   return false;        

         return true;
         }




         TDelay xvGetFastNodeDelay(xvNodeType ixvNode){   

                switch(ixvNode){  

                 case xvLogicRegRead : return xvDelayFastRegRead;  break;
                 case xvLogicRegWrite: return xvDelayFastRegWrite; break;
                 case xvLogicMemLoad : return xvDelayFastMemLoad;  break;
                 case xvLogicMemStore: return xvDelayFastMemStore; break;
                 case xvLogicOpADD   : return xvDelayFastOpADD;    break;   
                 case xvLogicOpSUB   : return xvDelayFastOpSUB;    break;
                 case xvLogicOpMUL   : return xvDelayFastOpMUL;    break;
                 case xvLogicOpDIV   : return xvDelayFastOpDIV;    break;
                 case xvLogicOpRSHF  : return xvDelayFastOpRSHF;   break;
                 case xvLogicOpLSHF  : return xvDelayFastOpLSHF;   break;
                 case xvLogicOpCMP   : return xvDelayFastOpCMP;    break;
                 case xvLogicOpAND   : return xvDelayFastOpAND;    break;
                 case xvLogicOpOR    : return xvDelayFastOpOR;     break;

                 default             : return -1;                  break;
                 }
         }	 

       
         // in here we don't care and not implement                                                 
         TDelay xvGetEdgeDelay(xvEdgeType ixvEdge){
                return 0;
         }


  };
}
#endif 
