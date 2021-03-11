#!/usr/bin/env python3

def gen_pkt(List):
    print("C to Python :")
    print(List)
    p = "This is Python Data !"
    print("python print :"+p)
    byte = p.encode()
    return byte
