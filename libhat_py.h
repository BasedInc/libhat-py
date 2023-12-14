#pragma once

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) ptrdiff_t libhat_find_pattern(const char* pattern, PyObject* memory_view);

#ifdef __cplusplus
}
#endif
