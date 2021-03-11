#include<Python.h>
#include<stdlib.h>

static PyObject *pModule  = NULL;
static PyObject *pFunc    = NULL;
static PyObject *pDict    = NULL;
static PyObject *pReturn  = NULL;
static PyObject *ArgList  = NULL;
static PyGILState_STATE py_state;

extern void c_py_init(){
    int i;
    double cArray[] = {1,2,3,4,5,6,};
    Py_Initialize();

    py_state = PyGILState_Ensure();

    pModule = PyImport_ImportModule("py_gen");
    pDict   = PyModule_GetDict(pModule);
    pFunc   = PyDict_GetItemString(pDict,"gen_pkt");

    PyObject *PyList = PyList_New(6);
    ArgList = PyTuple_New(1);

    for(i = 0; i < PyList_Size(PyList); i++){
        PyList_SetItem(PyList, i, PyFloat_FromDouble(cArray[i]));
    }

    PyTuple_SetItem(ArgList, 0, PyList);
    printf("initialize Python runtime !\n");
}

extern void c_py_final(){
    Py_DECREF(pModule); 
    Py_DECREF(pFunc  ); 
    Py_DECREF(pDict  ); 
    Py_DECREF(pReturn); 
    Py_DECREF(ArgList); 
    PyGILState_Release(py_state);
    Py_Finalize();
    printf("finalize Python runtime !\n");
}

//static unsigned char tmp[256] = {0};
extern void c_py_gen_packet(){
    int num;
    int i;
    char *result;

    pReturn = PyObject_CallObject(pFunc, ArgList);

    if(PyBytes_Check(pReturn)){
        num = PyBytes_Size(pReturn);
        result = PyBytes_AsString(pReturn);
        //memcpy(pkt,result,num);
        for( i = 0; i < num; i++){
            printf("%02X ", result[i]);
        }
        
        printf("\n");
    } else {
        printf("Get No Bytes Form Python !!!\n");
    }
}

int main( int argc, char* args[] ){
    
    c_py_init();
    
    c_py_gen_packet();

    c_py_final();
    
    return 0;
}
