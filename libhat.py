import ctypes
from typing import Optional

libhat_library = ctypes.CDLL("libhat_py")


def find_pattern(pattern: str, arr: memoryview) -> Optional[int]:
    func = libhat_library.libhat_find_pattern
    func.argtypes = [ctypes.c_char_p, ctypes.py_object]
    func.restype = ctypes.c_longlong
    result = func(pattern.encode("ascii", "ignore"), arr)
    return int(result) if result != -1 else None
