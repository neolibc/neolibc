#ifndef _NIO_FORMAT_H
#define _NIO_FORMAT_H

// Based on the basic types listed here:
// https://en.wikipedia.org/wiki/C_data_types
typedef enum _nioFormatterKind {
    // Characters.
    // The signedness of char is not defined by the
    // C standard, so we provide the default as well
    // as explicitly signed and unsigned versions.
    NIO_FORMATTER_CHAR,
    NIO_FORMATTER_SCHAR,
    NIO_FORMATTER_UCHAR,

    // Short integers.
    // At least 16 bits according to the standard.
    NIO_FORMATTER_SHRT,
    NIO_FORMATTER_USHRT,

    // Integers.
    // At least 16 bits according to the standard.
    // On Intel-compatible 32- and 64-bit platforms,
    // these are 32 bits. 
    NIO_FORMATTER_INT,
    NIO_FORMATTER_UINT,

    // Long integers.
    // At least 32 bits according to the standard.
    // 64 bits on x86 and x64.
    NIO_FORMATTER_LONG,
    NIO_FORMATTER_ULONG,

    // Long, long integers.
    // At least 64 bits on all platforms.
    NIO_FORMATTER_LLONG,
    NIO_FORMATTER_ULLONG,

    // Floating-point reals.
    // Sizes vary, but double always has double
    // precision and should, by default, be printed
    // with more digits.
    NIO_FORMATTER_FLOAT,
    NIO_FORMATTER_DOUBLE,
    NIO_FORMATTER_LDOUBLE,

    // Native null-terminated C strings.
    // The null-terminator is MANDATORY for this
    // variant's implementation to function.
    NIO_FORMATTER_CSTR,

    // *TODO*: Add NeoString* support.
    // NIO_FORMATTER_STR,
} NioFormatterKind;

typedef struct _nioFormatter {
    NioFormatterKind kind;
    union {
        // Characters.
        char as_char;
        unsigned char as_uchar;
        signed char as_schar;

        // Short integers.
        short as_shrt;
        unsigned short as_ushrt;

        // Integers.
        int as_int;
        unsigned as_uint;

        // Long integers.
        long as_long;
        unsigned long as_ulong;

        // Long, long integers.
        long long as_llong;
        unsigned long long as_ullong;

        // Floating-point reals.
        float as_float;
        double as_double;
        long double as_ldouble;

        // Native null-terminated C strings.
        const char *as_cstr;
    };
} NioFormatter;

// Characters.

static inline NioFormatter nio_char(char val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_CHAR, .as_char = val };
}

static inline NioFormatter nio_uchar(unsigned char val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_UCHAR, .as_uchar = val };
}

static inline NioFormatter nio_schar(signed char val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_SCHAR, .as_schar = val };
}


// Short integers.

static inline NioFormatter nio_shrt(short val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_SHRT, .as_shrt = val };
}

static inline NioFormatter nio_ushrt(unsigned short val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_USHRT, .as_ushrt = val }; 
}


// Integers.

static inline NioFormatter nio_int(int val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_INT, .as_int = val };
}

static inline NioFormatter nio_uint(unsigned val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_UINT, .as_uint = val };
}


// Long integers.

static inline NioFormatter nio_long(long val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_LONG, .as_long = val };
}

static inline NioFormatter nio_ulong(unsigned long val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_ULONG, .as_ulong = val };
}


// Long, long integers.

static inline NioFormatter nio_llong(long long val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_LLONG, .as_llong = val };
}

static inline NioFormatter nio_ullong(unsigned long long val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_ULLONG, .as_ullong = val };
}


// Floating-point reals.

static inline NioFormatter nio_float(float val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_FLOAT, .as_float = val };
}

static inline NioFormatter nio_double(double val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_DOUBLE, .as_double = val };
}

static inline NioFormatter nio_ldouble(long double val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_LDOUBLE, .as_ldouble = val };
}


// Native null-terminated C strings.

static inline NioFormatter nio_cstr(const char *val) {
    return (NioFormatter) { .kind = NIO_FORMATTER_CSTR, .as_cstr = val };
}

#endif
