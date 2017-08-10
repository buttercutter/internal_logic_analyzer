// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vinternal_logic_analyzer_top__Syms.h"
#include "Vinternal_logic_analyzer_top.h"

// FUNCTIONS
Vinternal_logic_analyzer_top__Syms::Vinternal_logic_analyzer_top__Syms(Vinternal_logic_analyzer_top* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_activity(false)
	, __Vm_didInit(false)
	// Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scope names
}
