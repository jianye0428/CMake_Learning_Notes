#include <Python.h>

int main(int argc, char* argv[]) {
  PyObject *py_name, *py_module, *py_dict, *py_func;
  PyObject *py_args, *py_value;
  if (argc < 3) {
    fprintf(stderr, "Usage: pure-embedding python_file funcname [args]\n");
    return 1;
  }
  Py_Initialize();
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\".\")");
  py_name = PyUnicode_DecodeFSDefault(argv[1]);
  /* Error checking of py_name left out */
  py_module = PyImport_Import(py_name);
  Py_DECREF(py_name);
  if (py_module != NULL) {
    py_func = PyObject_GetAttrString(py_module, argv[2]);
    /* py_func is a new reference */
    if (py_func && PyCallable_Check(py_func)) {
      py_args = PyTuple_New(argc - 3);
      for (int i = 0; i < argc - 3; ++i) {
        py_value = PyLong_FromLong(atoi(argv[i + 3]));
        if (!py_value) {
          Py_DECREF(py_args);
          Py_DECREF(py_module);
          fprintf(stderr, "Cannot convert argument\n");
          return 1;
        }
        /* py_value reference stolen here: */
        PyTuple_SetItem(py_args, i, py_value);
      }
      py_value = PyObject_CallObject(py_func, py_args);
      Py_DECREF(py_args);
      if (py_value != NULL) {
        printf("Result of call: %ld\n", PyLong_AsLong(py_value));
        Py_DECREF(py_value);
      } else {
        Py_DECREF(py_func);
        Py_DECREF(py_module);
        PyErr_Print();
        fprintf(stderr, "Call failed\n");
        return 1;
      }
    } else {
      if (PyErr_Occurred()) PyErr_Print();
      fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
    }
    Py_XDECREF(py_func);
    Py_DECREF(py_module);
  } else {
    PyErr_Print();
    fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
    return 1;
  }
  Py_Finalize();
  return 0;
}