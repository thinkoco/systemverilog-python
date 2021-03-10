#!/usr/bin/env python3
from scapy.all import *

def gen_pkt(List):
    p=Ether(dst='33:32:33:44:55:66',src='33:22:22:34:56:33')/IP(ihl=5)/UDP(dport=0x4a00)/'This is Python Data !'
    p.show()
    return raw(p)
