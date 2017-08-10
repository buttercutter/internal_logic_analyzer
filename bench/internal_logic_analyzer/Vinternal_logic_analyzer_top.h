// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vinternal_logic_analyzer_top_H_
#define _Vinternal_logic_analyzer_top_H_

#include "verilated.h"
class Vinternal_logic_analyzer_top__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vinternal_logic_analyzer_top) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(i_trigger,0,0);
    //char	__VpadToAlign3[1];
    VL_IN(i_holdoff,31,0);
    VL_IN(i_data,31,0);
    VL_OUT(o_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(internal_logic_analyzer__DOT__primed,0,0);
    VL_SIG8(internal_logic_analyzer__DOT__stopped,0,0);
    VL_SIG8(internal_logic_analyzer__DOT__st__DOT__triggered,0,0);
    //char	__VpadToAlign23[1];
    VL_SIG(internal_logic_analyzer__DOT__waddr,31,0);
    VL_SIG(internal_logic_analyzer__DOT__rd__DOT__raddr,31,0);
    VL_SIG(internal_logic_analyzer__DOT__rd__DOT__this_addr,31,0);
    VL_SIG(internal_logic_analyzer__DOT__st__DOT__holdoff_counter,31,0);
    VL_SIG(internal_logic_analyzer__DOT__ram[1024],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign4141[3];
    VL_SIG(__Vm_traceActivity,31,0);
    //char	__VpadToAlign4148[4];
    VL_SIG(internal_logic_analyzer__DOT____Vcellout__wr__memory[1024],31,0);
    VL_SIG(internal_logic_analyzer__DOT____Vcellinp__rd__memory[1024],31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign12348[4];
    Vinternal_logic_analyzer_top__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vinternal_logic_analyzer_top& operator= (const Vinternal_logic_analyzer_top&);	///< Copying not allowed
    Vinternal_logic_analyzer_top(const Vinternal_logic_analyzer_top&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vinternal_logic_analyzer_top(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vinternal_logic_analyzer_top();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vinternal_logic_analyzer_top__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    void	_configure_coverage(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_initial__TOP__3(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
