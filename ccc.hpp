#ifndef CCC_HPP
#define CCC_HPP

#include <iostream>

#if defined(__unix) || defined(__unix__) || defined(unix) ||\
    defined(__linux) || defined(__linux__) || defined(linux) ||\
    defined(__MACH__) || defined(BSD) || defined(__GNU__)
        #define CCC_UNIX
#endif

#if defined(_WIN64) || defined(_WIN32) || defined(_WIN16) ||\
    defined(__WIN64__) || defined(__WIN32__) || defined(__WIN16__) ||\
    defined(WINDOWS) || defined(__WINDOWS__)
        #define CCC_WINDOWS
        #include <windows.h>

        #error "not supported yet"
#endif

namespace ccc {

enum font {
    f_0, // the same as d_font
    f_1,
    f_2,
    f_3,
    f_4,
    f_5,
    f_6,
    f_7,
    f_8,
    f_9
};

enum color_f {
    cf_black,
    cf_red,
    cf_green,
    cf_yellow,
    cf_blue,
    cf_magenta,
    cf_cyan,
    cf_white
};

enum color_b {
    cb_black,
    cb_red,
    cb_green,
    cb_yellow,
    cb_blue,
    cb_magenta,
    cb_cyan,
    cb_white
};

enum style {
    s_font = 10,
    s_color_f = 30,
    s_color_b = 40,

    s_bold = 1,
    s_faint = 2,

    s_italic = 3,
    s_fraktur = 20,

    s_underline_single = 4,
    s_underline_double = 21,

    s_blink_slow = 5,
    s_blink_rapid = 6,

    s_framed = 51,
    s_encircled = 52,

    s_negative = 7,
    s_conceal = 8,
    s_delete = 9,
    s_overlined = 53
};

enum disable {
    d_all = 0,
    d_font = 10,
    d_color_f = 39,
    d_color_b = 49,

    d_intensity = 22,
    d_fontstyle = 23,
    d_underline = 24,
    d_blink = 25,
    d_border = 54,

    d_negative = 27,
    d_conceal = 28,
    d_delete = 29,
    d_overlined = 55
};

inline std::ostream &operator<<(std::ostream &s, const font &c) {
    #if defined(CCC_UNIX)
        return s << '\e' << '[' << (int) (s_font + c) << 'm';
    #elif defined(CCC_WINDOWS)
        // TODO

        assert(s == std::cout);

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buf_info;
        GetConsoleScreenBufferInfo(handle, &buf_info);
        SetConsoleTextAttribute(hStdOut, /* TODO */);

        return s;
    #endif
}

inline std::ostream &operator<<(std::ostream &s, const color_f &c) {
    #if defined(CCC_UNIX)
        return s << '\e' << '[' << (int) (s_color_f + c) << 'm';
    #elif defined(CCC_WINDOWS)
        // TODO

        assert(s == std::cout);

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buf_info;
        GetConsoleScreenBufferInfo(handle, &buf_info);
        SetConsoleTextAttribute(hStdOut, /* TODO */);

        return s;
    #endif
}

inline std::ostream &operator<<(std::ostream &s, const color_b &c) {
    #if defined(CCC_UNIX)
        return s << '\e' << '[' << (int) (s_color_b + c) << 'm';
    #elif defined(CCC_WINDOWS)
        // TODO

        assert(s == std::cout);

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buf_info;
        GetConsoleScreenBufferInfo(handle, &buf_info);
        SetConsoleTextAttribute(hStdOut, /* TODO */);

        return s;
    #endif
}

inline std::ostream &operator<<(std::ostream &s, const style &c) {
    #if defined(CCC_UNIX)
        return s << '\e' << '[' << (int) c << 'm';
    #elif defined(CCC_WINDOWS)
        // TODO

        assert(s == std::cout);

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buf_info;
        GetConsoleScreenBufferInfo(handle, &buf_info);
        SetConsoleTextAttribute(hStdOut, /* TODO */);

        return s;
    #endif
}

inline std::ostream &operator<<(std::ostream &s, const disable &c) {
    #if defined(CCC_UNIX)
        return s << '\e' << '[' << (int) c << 'm';
    #elif defined(CCC_WINDOWS)
        // TODO

        assert(s == std::cout);

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buf_info;
        GetConsoleScreenBufferInfo(handle, &buf_info);
        SetConsoleTextAttribute(hStdOut, /* TODO */);

        return s;
    #endif
}

}

#endif
