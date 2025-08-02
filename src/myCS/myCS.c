#include "../../include/myCS.h"

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

string get_string(const string format, ...) {
  va_list args;
  va_start(args, format);

  return vget_string(format, args);
}

string vget_string(const string format, va_list args) {
  if (format) {
    if (vprintf(format, args) < 0) {
      return NULL;
    }

    fflush(stdout);
  }

  string str = NULL;

  size_t capacity = 0;

  size_t size = 0;

  char c;

  while ((c = fgetc(stdin)) != '\n' && c != EOF) {
    if (size + 1 > capacity) {
      if (capacity == SIZE_MAX) {
        free(str);
        return NULL;
      }

      capacity++;

      string temp = realloc(str, capacity);

      if (!temp) {
        free(str);
        return NULL;
      }

      str = temp;
    }

    str[size++] = c;
  }

  if (size == 0 && c == EOF) {
    free(str);
    return NULL;
  };

  if (size == SIZE_MAX) {
    free(str);
    return NULL;
  }

  string s = realloc(str, size + 1);

  if (!s) {
    free(str);
    return NULL;
  };

  s[size] = '\0';

  return s;
}

char get_char(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

  if (strlen(str) != 1) {
    free(str);
    errno = EINVAL;

    return 0;
  }

  return str[0];
}

int get_int(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

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

long get_long(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

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

long long get_long_long(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

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

float get_float(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

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

double get_double(const string format, ...) {
  va_list args;
  va_start(args, format);

  string str = vget_string(format, args);

  va_end(args);

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
