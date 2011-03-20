
#ifndef _xvGlobalTable_H
#define _xvGlobalTable_H

#include <iostream>

#define DefTDelay  float 


namespace xVerilog {

enum xvModeType {
     xvModeFast,
     xvModeNormal,
     xvModeSlow
};

    
// @ Node logic type
enum xvNodeType {
     xvLogicRegRead,
     xvLogicRegWrite,
     xvLogicMemLoad,
     xvLogicMemStore,
     xvLogicOpADD,
     xvLogicOpSUB,
     xvLogicOpMUL,
     xvLogicOpDIV,
     xvLogicOpRSHF,
     xvLogicOpLSHF,
     xvLogicOpCMP,
     xvLogicOpAND,
     xvLogicOpOR,
     xvLogicNop
};


// @ unint cycle define

#define xvDelayFastRegRead   0   
#define xvDelayNormalRegRead 0
#define xvDelaySlowRegRead   0.1

#define xvDelayFastRegWrite   0   
#define xvDelayNormalRegWrite 0
#define xvDelaySlowRegWrite   0.1

// @ MemLoad
#define xvDelayFastMemLoad   1.5
#define xvDelayNormalMemLoad 1.7
#define xvDelaySlowMemLoad   1.9

// @ MemStore
#define xvDelayFastMemStore   1.7
#define xvDelayNormalMemStore 1.9
#define xvDelaySlowMemStore   2.1

// @ OP ADD
#define xvDelayFastOpADD     0.8
#define xvDelayNormalOpADD   0.4
#define xvDelaySlowOpADD     0.5

// @ Op SUB
#define xvDelayFastOpSUB     0.4
#define xvDelayNormalOpSUB   0.5
#define xvDelaySlowOpSUB     0.6

// @ OP MUL
#define xvDelayFastOpMUL     0.5
#define xvDelayNormalOpMUL   0.6
#define xvDelaySlowOpMUL     0.7     

// @ OP DIV
#define xvDelayFastOpDIV     0.6
#define xvDelayNormalOpDIV   0.7
#define xvDelaySlowOpDIV     0.8

// @ OP RSHF
#define xvDelayFastOpRSHF    0
#define xvDelayNormalOpRSHF  0
#define xvDelaySlowOpRSHF    0.1

// @ OP LSHF
#define xvDelayFastOpLSHF    0
#define xvDelayNormalOpLSHF  0
#define xvDelaySLowOpLSHF    0.1

// @ OP CMP
#define xvDelayFastOpCMP     0
#define xvDelayNormalOpCMP   0
#define xvDelaySlowOpCMP     0.1

// @ OP AND
#define xvDelayFastOpAND     0
#define xvDelayNormalOpAND   0
#define xvDelaySlowOpAND     0

// @ OP OR
#define xvDelayFastOpOR      0
#define xvDelayNormalOpOR    0
#define xvDelaySlowOpOR      0


enum xvEdgeType {
     xvPointDirect,
     xvPointFeedBack,
     xvPointNop
};

}
#endif
