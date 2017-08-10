// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vinternal_logic_analyzer_top__Syms_H_
#define _Vinternal_logic_analyzer_top__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vinternal_logic_analyzer_top.h"

// SYMS CLASS
class Vinternal_logic_analyzer_top__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool	__Vm_activity;		///< Used by trace routines to determine change occurred
    bool	__Vm_didInit;
    //char	__VpadToAlign10[6];
    
    // SUBCELL STATE
    Vinternal_logic_analyzer_top*  TOPp;
    
    // COVERAGE
    
    // SCOPE NAMES
    
    // CREATORS
    Vinternal_logic_analyzer_top__Syms(Vinternal_logic_analyzer_top* topp, const char* namep);
    ~Vinternal_logic_analyzer_top__Syms() {};
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r;}
    
} VL_ATTR_ALIGNED(64);

#endif  /*guard*/
