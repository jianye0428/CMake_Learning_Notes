#include <Python.h>
int main(int argc, char *argv[]) {
  /* optional but recommended */
  Py_SetProgramName(argv[0]);
  Py_Initialize();
  PyRun_SimpleString("print('Today is Tuesday!')\n");
  Py_Finalize();
  return 0;
}