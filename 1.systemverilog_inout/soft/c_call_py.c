#include<Python.h>
#include<svdpi.h>
#include<stdlib.h>

#ifndef PYTHON_PATH
#error You must define the PYTHONPATH to the python file in gcc compiler with -D
#endif

static PyObject *pModule  = NULL;
static PyObject *pFunc    = NULL;
static PyObject *pDict    = NULL;
static PyObject *pReturn  = NULL;
static PyObject *PyList   = NULL;
static PyObject *ArgList  = NULL;
static PyGILState_STATE py_state;

extern void c_py_init(){
    char *append_path = malloc(sizeof(char) * 1000);
    append_path = PYTHON_PATH":.";
    setenv("PYTHONPATH",append_path,1);//Set PYTHONPATH TO working directory https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/setenv.htm
    printf("PYTHONPATH is:%s !\n", append_path);

    Py_Initialize();

    py_state = PyGILState_Ensure();

    pModule = PyImport_ImportModule("py_gen");
    printf("Import python script is py_gen.py !\n");
    pDict   = PyModule_GetDict(pModule);
    pFunc   = PyDict_GetItemString(pDict,"gen_pkt");
    printf("Python function is gen_pkt !\n");

    PyList  = PyList_New(2);
    ArgList = PyTuple_New(1);
    printf("initialize Python runtime !\n");
}

extern void c_py_final(){
    PyGILState_Release(py_state);
    Py_Finalize();
    printf("finalize Python runtime !\n");
}

static unsigned char tmp[256] = {0};
extern void c_py_gen_packet( /*input*/const svBitVecVal *mode ,/*output*/ svBitVecVal *pkt, /*output*/ svBitVecVal *len){
    int num;
    int i;
    unsigned char *result;
    
    PyList_SetItem(PyList, 0, PyLong_FromLong(mode[0]) );
    PyList_SetItem(PyList, 1, PyLong_FromLong(mode[1]) );

    PyTuple_SetItem(ArgList, 0, PyList);

    pReturn = PyObject_CallObject(pFunc, ArgList);

    if(PyBytes_Check(pReturn)){
        num = PyBytes_Size(pReturn);
        result = PyBytes_AsString(pReturn);
        //memcpy(pkt,result,num);
        for( i = 0; i < num; i++){
            tmp[255-i] = result[i];
            printf("%02X ",result[i]);
        }
        memcpy(pkt, tmp, 256);

        *len = num;
        printf("\n");
    } else {
        printf("Get No Bytes Form Python !!!\n");
    }
}
