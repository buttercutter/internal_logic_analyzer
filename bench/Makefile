TARGET=internal_logic_analyzer
.PHONY: $(TARGET)
RTLSRC=../rtl
all: $(TARGET)

DESIGN_FILES=$(TARGET)_top.v read_mem.v write_mem.v stop.v
LDFLAGS=
CFLAGS=-g -O3

DEBUG_ON = --debug --trace-dups --gdbbt
VALGRIND_ON = $(DEBUG_ON) --gdb "valgrind -v --leak-check=yes"

$(TARGET):
	$(PERL) verilator -Wno-fatal -I$(RTLSRC) --cc $(DESIGN_FILES) --trace --exe ../$(@).cpp  -Mdir $(@) -CFLAGS "$(CFLAGS)"
	make -C $(@) -f V$(@)_top.mk
clean:: 
	rm -rf *.o $(TARGET)
distclean:: clean
	rm -rf *~ *.txt *.vcd *.mif *.orig
