// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vinternal_logic_analyzer_top__Syms.h"


//======================

void Vinternal_logic_analyzer_top::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vinternal_logic_analyzer_top::traceInit, &Vinternal_logic_analyzer_top::traceFull, &Vinternal_logic_analyzer_top::traceChg, this);
}
void Vinternal_logic_analyzer_top::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vinternal_logic_analyzer_top* t=(Vinternal_logic_analyzer_top*)userthis;
    Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vinternal_logic_analyzer_top::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vinternal_logic_analyzer_top* t=(Vinternal_logic_analyzer_top*)userthis;
    Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vinternal_logic_analyzer_top::traceInitThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vinternal_logic_analyzer_top::traceFullThis(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vinternal_logic_analyzer_top::traceInitThis__1(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+9,"clk",-1);
	vcdp->declBit  (c+10,"reset",-1);
	vcdp->declBit  (c+11,"i_trigger",-1);
	vcdp->declBus  (c+12,"i_holdoff",-1,31,0);
	vcdp->declBus  (c+13,"i_data",-1,31,0);
	vcdp->declBus  (c+14,"o_data",-1,31,0);
	vcdp->declBit  (c+9,"internal_logic_analyzer clk",-1);
	vcdp->declBit  (c+10,"internal_logic_analyzer reset",-1);
	vcdp->declBit  (c+11,"internal_logic_analyzer i_trigger",-1);
	vcdp->declBus  (c+12,"internal_logic_analyzer i_holdoff",-1,31,0);
	vcdp->declBus  (c+13,"internal_logic_analyzer i_data",-1,31,0);
	vcdp->declBus  (c+14,"internal_logic_analyzer o_data",-1,31,0);
	vcdp->declBus  (c+4,"internal_logic_analyzer waddr",-1,31,0);
	vcdp->declBit  (c+1,"internal_logic_analyzer primed",-1);
	vcdp->declBit  (c+5,"internal_logic_analyzer stopped",-1);
	// Tracing: internal_logic_analyzer ram // Ignored: Wide memory > --trace-max-array ents at ../rtl/internal_logic_analyzer_top.v:16
	vcdp->declBit  (c+9,"internal_logic_analyzer wr clk",-1);
	vcdp->declBit  (c+10,"internal_logic_analyzer wr reset",-1);
	vcdp->declBit  (c+6,"internal_logic_analyzer wr write_enable",-1);
	vcdp->declBus  (c+13,"internal_logic_analyzer wr i_data",-1,31,0);
	vcdp->declBit  (c+1,"internal_logic_analyzer wr primed",-1);
	vcdp->declBus  (c+4,"internal_logic_analyzer wr waddr",-1,31,0);
	// Tracing: internal_logic_analyzer wr memory // Ignored: Wide memory > --trace-max-array ents at ../rtl/write_mem.v:10
	vcdp->declBit  (c+9,"internal_logic_analyzer rd clk",-1);
	vcdp->declBit  (c+10,"internal_logic_analyzer rd reset",-1);
	vcdp->declBit  (c+5,"internal_logic_analyzer rd read_enable",-1);
	vcdp->declBus  (c+4,"internal_logic_analyzer rd waddr",-1,31,0);
	// Tracing: internal_logic_analyzer rd memory // Ignored: Wide memory > --trace-max-array ents at ../rtl/read_mem.v:7
	vcdp->declBus  (c+14,"internal_logic_analyzer rd o_data",-1,31,0);
	vcdp->declBus  (c+2,"internal_logic_analyzer rd raddr",-1,31,0);
	vcdp->declBus  (c+7,"internal_logic_analyzer rd this_addr",-1,31,0);
	vcdp->declBit  (c+9,"internal_logic_analyzer st clk",-1);
	vcdp->declBit  (c+10,"internal_logic_analyzer st reset",-1);
	vcdp->declBit  (c+1,"internal_logic_analyzer st primed",-1);
	vcdp->declBit  (c+11,"internal_logic_analyzer st i_trigger",-1);
	vcdp->declBus  (c+4,"internal_logic_analyzer st waddr",-1,31,0);
	vcdp->declBus  (c+12,"internal_logic_analyzer st i_holdoff",-1,31,0);
	vcdp->declBit  (c+5,"internal_logic_analyzer st stopped",-1);
	vcdp->declBit  (c+8,"internal_logic_analyzer st triggered",-1);
	vcdp->declBus  (c+3,"internal_logic_analyzer st holdoff_counter",-1,31,0);
    }
}

void Vinternal_logic_analyzer_top::traceFullThis__1(Vinternal_logic_analyzer_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vinternal_logic_analyzer_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->internal_logic_analyzer__DOT__primed));
	vcdp->fullBus  (c+2,(vlTOPp->internal_logic_analyzer__DOT__rd__DOT__raddr),32);
	vcdp->fullBus  (c+3,(vlTOPp->internal_logic_analyzer__DOT__st__DOT__holdoff_counter),32);
	vcdp->fullBus  (c+4,(vlTOPp->internal_logic_analyzer__DOT__waddr),32);
	vcdp->fullBit  (c+5,(vlTOPp->internal_logic_analyzer__DOT__stopped));
	vcdp->fullBit  (c+6,((1U & (~ (IData)(vlTOPp->internal_logic_analyzer__DOT__stopped)))));
	vcdp->fullBus  (c+7,(vlTOPp->internal_logic_analyzer__DOT__rd__DOT__this_addr),32);
	vcdp->fullBit  (c+8,(vlTOPp->internal_logic_analyzer__DOT__st__DOT__triggered));
	vcdp->fullBit  (c+9,(vlTOPp->clk));
	vcdp->fullBit  (c+10,(vlTOPp->reset));
	vcdp->fullBit  (c+11,(vlTOPp->i_trigger));
	vcdp->fullBus  (c+12,(vlTOPp->i_holdoff),32);
	vcdp->fullBus  (c+13,(vlTOPp->i_data),32);
	vcdp->fullBus  (c+14,(vlTOPp->o_data),32);
    }
}
