// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vinternal_logic_analyzer_top__Syms.h"


//======================

void Vinternal_logic_analyzer_top::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vinternal_logic_analyzer_top* t=(Vinternal_logic_analyzer_top*)userthis;
    Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vinternal_logic_analyzer_top::traceChgThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vinternal_logic_analyzer_top::traceChgThis__2(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->internal_logic_analyzer__DOT__primed));
	vcdp->chgBus  (c+2,(vlTOPp->internal_logic_analyzer__DOT__rd__DOT__raddr),32);
	vcdp->chgBus  (c+3,(vlTOPp->internal_logic_analyzer__DOT__st__DOT__holdoff_counter),32);
    }
}

void Vinternal_logic_analyzer_top::traceChgThis__3(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+4,(vlTOPp->internal_logic_analyzer__DOT__waddr),32);
	vcdp->chgBit  (c+5,(vlTOPp->internal_logic_analyzer__DOT__stopped));
	vcdp->chgBit  (c+6,((1U & (~ (IData)(vlTOPp->internal_logic_analyzer__DOT__stopped)))));
	vcdp->chgBus  (c+7,(vlTOPp->internal_logic_analyzer__DOT__rd__DOT__this_addr),32);
	vcdp->chgBit  (c+8,(vlTOPp->internal_logic_analyzer__DOT__st__DOT__triggered));
    }
}

void Vinternal_logic_analyzer_top::traceChgThis__4(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+9,(vlTOPp->clk));
	vcdp->chgBit  (c+10,(vlTOPp->reset));
	vcdp->chgBit  (c+11,(vlTOPp->i_trigger));
	vcdp->chgBus  (c+12,(vlTOPp->i_holdoff),32);
	vcdp->chgBus  (c+13,(vlTOPp->i_data),32);
	vcdp->chgBus  (c+14,(vlTOPp->o_data),32);
    }
}
