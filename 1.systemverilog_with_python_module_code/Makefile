
all:	clean comp run

clean:
	\rm -rf simv* csrc* *.log __pycache__ ucli.key vc_hdrs.h stack.info.*
comp:
	vcs -full64 -LDFLAGS -Wl,--no-as-needed -CC -lpython3.6m -lpthread -ldl -lutil -lm -LDFLAGS -lpython3.6m -CC -I/usr/include/python3.6m -CC -I. -sverilog gen_pkt_tb.sv c_call_py.c -l comp.log
run:
	export PYTHONPATH=.:./scapy-2.4.4  && ./simv -l run.log
