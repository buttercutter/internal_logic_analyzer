# internal_logic_analyzer
An internal logic analyzer/scope for FPGA's

```
internal_logic_analyzer_top(clk, reset, i_trigger, i_holdoff, i_data, o_data, o_primed)
```

* clk : your system clock to be used as sampling clock

* reset : a signal to restart the logic sampling proccess once stopped by i_trigger

* i_trigger : a signal to trigger the stopping of logic sampling process 

* i_holdoff : a signal is used to delay the stopping of logic sampling process upon i_trigger is aserted for one clock cycle

* i_data : this is the FPGA signal that we are interested in capturing/sampling

* o_data : output data which could be read out for waveform viewing or debugging purpose

* o_primed : a signal to signify that i_trigger could be asserted. *DO NOT* ever assert i_trigger before o_primed goes HIGH
