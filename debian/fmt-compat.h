// Compatibility shim for GCC < 13 which lacks C++20 <format>.
// This header is force-included via -include in debian/rules.
// It provides std::format, std::formatter, and related types
// by aliasing them to their fmt library equivalents.
#pragma once

#if defined(__GNUC__) && (__GNUC__ < 13)

#include <fmt/format.h>

namespace std {
    using ::fmt::format;
    using ::fmt::format_to;
    using ::fmt::vformat;
    using ::fmt::make_format_args;

    template<typename... Args>
    using format_string = ::fmt::format_string<Args...>;

    template<typename... Args>
    struct formatter: ::fmt::formatter<Args...> {};
}

#endif
