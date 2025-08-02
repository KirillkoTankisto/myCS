#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char *string;

int println(const string format, ...);

string get_string(const string format, ...);

string vget_string(const string format, va_list args);

char get_char(const string format, ...);

int get_int(const string format, ...);

int str_to_int(const string str);

long get_long(const string format, ...);

long str_to_long(const string str);

long long get_long_long(const string format, ...);

long long str_to_long_long(const string str);

float get_float(const string format, ...);

float str_to_float(const string str);

double get_double(const string format, ...);

double str_to_double(const string str);
