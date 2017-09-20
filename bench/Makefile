TARGET=internal_logic_analyzer
.PHONY: $(TARGET)
RTLSRC=../rtl
all: $(TARGET)

test=test_$(TARGET)
DESIGN_FILES=$(TARGET)_top.v memory_block.v read_address_controller.v write_address_controller.v stop.v
ADDITIONAL_DESIGN_FILES=test_$(TARGET)_top.v signal_gen.v check_data.v
LDFLAGS=
CFLAGS=-g -O3

DEBUG_ON = --debug --trace-dups --gdbbt
VALGRIND_ON = $(DEBUG_ON) --gdb "valgrind -v --leak-check=yes"

$(TARGET):
	$(PERL) verilator -Wall -I$(RTLSRC) --cc $(DESIGN_FILES) --trace --exe ../$(@).cpp  -Mdir $(@) -CFLAGS "$(CFLAGS)" 
	make -C $(@) -f V$(@)_top.mk

.PHONY: test
test: $(test)

$(test):
	$(PERL) verilator -Wall -I$(RTLSRC) --cc $(ADDITIONAL_DESIGN_FILES) $(DESIGN_FILES) --trace --exe ../$(@).cpp  -Mdir $(@) -CFLAGS "$(CFLAGS)" 
	make -C $(@) -f V$(@)_top.mk

clean:
	rm -rf *.o $(TARGET) $(test)

distclean:: clean
	rm -rf *~ *.txt *.vcd *.mif *.orig
