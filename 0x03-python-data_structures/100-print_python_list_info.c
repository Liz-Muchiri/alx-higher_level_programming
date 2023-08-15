#include <Python.h>
#include <stdio.h>

/**
 * print_python_list_info - Prints basic information about a Python list.
 * @p: PyObject representing the Python list.
 */
void print_python_list_info(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t size = PyList_Size(p);

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (Py_ssize_t i = 0; i < size; ++i)
    {
        PyObject *item = PyList_GetItem(p, i);
        printf("Element %zd: ", i);

        if (PyUnicode_Check(item))
            printf("str\n");
        else if (PyLong_Check(item))
            printf("int\n");
        else if (PyFloat_Check(item))
            printf("float\n");
        else if (PyTuple_Check(item))
            printf("tuple\n");
        else if (PyList_Check(item))
            printf("list\n");
        else
            printf("%s\n", Py_TYPE(item)->tp_name);
    }
}
