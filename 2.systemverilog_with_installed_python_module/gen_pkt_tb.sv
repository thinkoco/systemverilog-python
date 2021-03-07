
module hello_world;

import "DPI-C" function void c_py_init();
import "DPI-C" function void c_py_final();
import "DPI-C" function void c_py_gen_packet(output bit[2047:0] pkt, output bit [7:0] len);

bit [15:0][127:0] data;
bit [7 :0]        len ;

    initial begin
        c_py_init();
        c_py_gen_packet(data,len);
        
        $display("print data in systemverilog !");
        
        $display("get len  ='h%h",len );
        $display("get data ='h%h",data);
        $display("get data = %s",data);
        
        c_py_final();
        $finish();
    end
endmodule

