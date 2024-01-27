cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(python_interperter LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "print('Hello, python interpreter!')"
    RESULT_VARIABLE RESULT_STATUS
    OUTPUT_VARIABLE RESULT_OUTPUT
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# message(STATUS "RESULT_VARIABLE is: ${RESULT_STATUS}")
# message(STATUS "OUTPUT_VARIABLE is: ${RESULT_OUTPUT}")

include(CMakePrintHelpers)
cmake_print_variables(RESULT_STATUS RESULT_OUTPUT)