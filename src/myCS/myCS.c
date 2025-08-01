#include "../../include/myCS.h"

#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int println(const string format, ...) {

  va_list args;
  va_start(args, format);

  int chars_printed = vprintf(format, args);

  va_end(args);

  if (chars_printed < 0) {
    return chars_printed;
  };

  if (putchar('\n') == EOF) {
    return EOF;
  };

  return chars_printed + 1;
}

string get_string(const string prompt, int buffer_size) {

  println("%s", prompt);

  string buffer = malloc(buffer_size);

  if (!buffer)
    return NULL;

  if (!fgets(buffer, buffer_size, stdin)) {
    free(buffer);
    return NULL;
  };

  buffer[strcspn(buffer, "\n")] = '\0';

  return buffer;
}

char get_char(const string prompt, int buffer_size) {
  string str = get_string(prompt, buffer_size);

  if (strlen(str) != 1) {
    free(str);
    errno = EINVAL;

    return 0;
  }

  return str[0];
}

int get_int(const string prompt, int buffer_size) {

  string str = get_string(prompt, buffer_size);

  if (str == NULL) {
    free(str);
    errno = EINVAL;

    return 0;
  }

  int num = str_to_int(str);

  free(str);

  if (errno != 0) {
    return 0;
  }

  return num;
}

int str_to_int(const string str) {

  string tail;

  int num = strtol(str, &tail, 10);

  if (str == tail || *tail != '\0') {
    errno = EINVAL;

    return 0;
  }

  if (errno == ERANGE) {
    return 0;
  }

  if (num < INT_MIN || num > INT_MAX) {
    errno = ERANGE;
    return 0;
  }

  return num;
}

long get_long(const string prompt, int buffer_size) {

  string str = get_string(prompt, buffer_size);

  if (str == NULL) {
    free(str);
    errno = EINVAL;

    return 0;
  }

  long num = str_to_long(str);

  free(str);

  return num;
}

long str_to_long(const string str) {

  string tail;

  long num = strtol(str, &tail, 10);

  if (str == tail || *tail != '\0') {
    errno = EINVAL;

    return 0;
  }

  if (errno == ERANGE) {
    return 0;
  }

  return num;
}

long long get_long_long(const string prompt, int buffer_size) {

  string str = get_string(prompt, buffer_size);

  if (str == NULL) {
    free(str);
    errno = EINVAL;

    return 0;
  }

  long long num = str_to_long_long(str);

  free(str);

  return num;
}

long long str_to_long_long(const string str) {

  string tail;

  long long num = strtoll(str, &tail, 10);

  if (str == tail || *tail != '\0') {
    errno = EINVAL;

    return 0;
  }

  if (errno == ERANGE) {
    return 0;
  }

  return num;
}

float get_float(const string prompt, int buffer_size) {

  string str = get_string(prompt, buffer_size);

  if (str == NULL) {
    free(str);
    errno = EINVAL;

    return 0;
  };

  float num = str_to_float(str);

  free(str);

  return num;
}

float str_to_float(const string str) {

  string tail;

  float num = strtof(str, &tail);

  if (str == tail || *tail != '\0') {
    errno = EINVAL;

    return 0.0f;
  };

  if (errno == ERANGE) {
    return 0.0f;
  };

  return num;
}

double get_double(const string prompt, int buffer_size) {

  string str = get_string(prompt, buffer_size);

  if (str == NULL) {
    free(str);
    errno = EINVAL;

    return 0;
  };

  double num = str_to_double(str);

  free(str);

  return num;
}

double str_to_double(const string str) {

  string tail;

  double num = strtod(str, &tail);

  if (str == tail || *tail != '\0') {
    errno = EINVAL;

    return 0;
  };

  if (errno == ERANGE) {
    return 0;
  };

  return num;
}
