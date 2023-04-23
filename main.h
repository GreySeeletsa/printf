#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unstd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUSE 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - Structure op
 * @fmt: format
 * @fn: function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Structure op
 * @fmt: format
 * @fmt_t: function
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle _print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/*These functions will print chars and string*/
int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/*These functions will print number*/
int print_int(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int pricision, int size);
int print_hex_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_hex_(va_list types, char map_to[], char buffer[], int flags,
		int width, int precision, int size);

/*This function will print characters that are not printable*/
int print_not_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/*This function will print memory address*/
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/*These functions will carry out other specifiers*/
int get_flags(const char *format, int *int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*This function will a print string in reverse*/
int print_revstr(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/*This function will print a string in rot 13*/
int print_strrot13(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/*These will handle the width*/
int write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_num(int positive, int index, char buffer[], int flags,
		int width, int precision, int size);
int write_n(int index, char buffer2[], int flags, int width, int precision,
		int len, char pd, char extra);
int write_ptr(char bufffer[], int index, int len, int width, int flags,
		char pd, char extra, int pd_start);
int write_unsigned(int negative, int index, char buffer[], int flags,
		int width, int precision, int size);

int printable(char);
int app_hex(char, char[], int);
int _digit(char);
long int conv_size_num(long int num, int size);
long int conv_size_unsigned(unisigned long int num, int size);

#endif
