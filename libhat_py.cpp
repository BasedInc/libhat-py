#include "libhat_py.h"

#include <libhat/Scanner.hpp>

extern "C" {
    ptrdiff_t libhat_find_pattern(const char* pattern, PyObject* memory_view) {
        const auto sig = hat::parse_signature(pattern);
        if (!sig.has_value()) {
            std::terminate();
        }

        if (!PyMemoryView_Check(memory_view)) {
            std::terminate();
        }

        const auto* buf = PyMemoryView_GET_BUFFER(memory_view);

        const auto begin = static_cast<const std::byte*>(buf->buf);
        const auto end = static_cast<const std::byte*>(buf->buf) + buf->len;

        const auto result = hat::find_pattern(begin, end, sig.value());
        return result.has_result() ? (result.get() - begin) : -1;
    }
}
