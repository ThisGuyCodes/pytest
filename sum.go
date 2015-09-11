package main

// #cgo pkg-config: python3
// #define Py_LIMITED_API
// #include <Python.h>
// int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
import "C"
import (
	"log"
	"time"
)

//export Sum
func Sum(self, args *C.PyObject) *C.PyObject {
	var a, b C.longlong
	if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
		return nil
	}
	return C.PyLong_FromLongLong(a + b)
}

//export Tick
func Tick(self, args *C.PyObject) *C.PyObject {
	go func() {
		for range time.NewTicker(time.Second).C {
			log.Println("tick")
		}
	}()
	return C.PyLong_FromLong(0)
}

func main() {}
