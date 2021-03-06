# systemverilog-python
Systemverilog DPI-C call Python function

## 0.systemverilog_only
```
    python3 -m pip install scapy
    cd 0.systemverilog_only
    export PYTHONPATH=.
    make
```
### logs
```
\rm -rf simv* csrc* *.log __pycache__ ucli.key vc_hdrs.h stack.info.*
vcs -full64 -LDFLAGS -Wl,--no-as-needed +incdir+./c -CC -lpython3.6m -CC -lpthread -CC -ldl -CC -lutil -lm -LDFLAGS -lpython3.6m -CC -I/usr/include/python3.6m -CC -I./ -sverilog gen_pkt_tb.sv c_call_py.c -l comp.log
                         Chronologic VCS (TM)
       Version O-2018.09-SP2_Full64 -- Sat Mar  6 23:51:16 2021
               Copyright (c) 1991-2018 by Synopsys Inc.
                         ALL RIGHTS RESERVED

This program is proprietary and confidential information of Synopsys Inc.
and may be used and disclosed only as authorized in a license agreement
controlling such use and disclosure.

Parsing design file 'gen_pkt_tb.sv'
Top Level Modules:
       hello_world
No TimeScale specified
Starting vcs inline pass...

1 module and 0 UDP read.
recompiling module hello_world
make[1]: Entering directory '/home/knat/tmp/c_call_py/0.systemverilog_only/csrc'
rm -f _csrc*.so pre_vcsobj_*.so share_vcsobj_*.so
gcc -w  -pipe -fPIC -lpython3.6m -lpthread -ldl -lutil -I/usr/include/python3.6m -I./ -O -I/opt/synopsys/O-2018.09-SP2/include    -c ../c_call_py.c
if [ -x ../simv ]; then chmod -x ../simv; fi
g++  -o ../simv    -Wl,-rpath-link=./ -Wl,-rpath='$ORIGIN'/simv.daidir/ -Wl,-rpath=./simv.daidir/ -Wl,-rpath='$ORIGIN'/simv.daidir//scsim.db.dir  -Wl,--no-as-needed -lpython3.6m -rdynamic  -Wl,-rpath=/opt/synopsys/O-2018.09-SP2/linux64/lib -L/opt/synopsys/O-2018.09-SP2/linux64/lib  c_call_py.o   objs/amcQw_d.o   _4021_archive_1.so  SIM_l.o      rmapats_mop.o rmapats.o rmar.o rmar_nd.o  rmar_llvm_0_1.o rmar_llvm_0_0.o          -lzerosoft_rt_stubs -lvirsim -lerrorinf -lsnpsmalloc -lvfs -lm    -lvcsnew -lsimprofile -luclinative /opt/synopsys/O-2018.09-SP2/linux64/lib/vcs_tls.o   -Wl,-whole-archive -lvcsucli -Wl,-no-whole-archive       ./../simv.daidir/vc_hdrs.o    /opt/synopsys/O-2018.09-SP2/linux64/lib/vcs_save_restore_new.o -ldl  -lc -lm -lpthread -ldl
../simv up to date
make[1]: Leaving directory '/home/knat/tmp/c_call_py/0.systemverilog_only/csrc'
CPU time: .160 seconds to compile + .141 seconds to elab + .251 seconds to link
./simv -l run.log
Chronologic VCS simulator copyright 1991-2018
Contains Synopsys proprietary information.
Compiler version O-2018.09-SP2_Full64; Runtime version O-2018.09-SP2_Full64;  Mar  6 23:51 2021
initialize Python runtime !
###[ Ethernet ]###
  dst       = 33:32:33:44:55:66
  src       = 33:22:22:34:56:33
  type      = IPv4
###[ IP ]###
     version   = 4
     ihl       = 5
     tos       = 0x0
     len       = None
     id        = 1
     flags     =
     frag      = 0
     ttl       = 64
     proto     = udp
     chksum    = None
     src       = 127.0.0.1
     dst       = 127.0.0.1
     \options   \
###[ UDP ]###
        sport     = domain
        dport     = 18944
        len       = None
        chksum    = None
###[ Raw ]###
           load      = 'This is Python Data !'

33 32 33 44 55 66 33 22 22 34 56 33 08 00 45 00 00 31 00 01 00 00 40 11 7C B9 7F 00 00 01 7F 00 00 01 00 35 4A 00 00 1D 2D EE 54 68 69 73 20 69 73 20 50 79 74 68 6F 6E 20 44 61 74 61 20 21
print data in systemverilog !
get len  ='h3f
get data ='h3332334455663322223456330800450000310001000040117cb97f0000017f00000100354a00001d2dee5468697320697320507974686f6e2044617461202100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
get data = 323DUf3""4V E  1   @|�     5J  -�This is Python Data !
finalize Python runtime !
$finish called from file "gen_pkt_tb.sv", line 22.
$finish at simulation time                    0
           V C S   S i m u l a t i o n   R e p o r t
Time: 0
CPU Time:      2.060 seconds;       Data structure size:   0.0Mb
Sat Mar  6 23:51:18 2021

```
