#include "../../include/myCS.h"

#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int game1(int argc, string *argv) {

  string name;
  void *allocated_name = NULL;

  if (argc < 2) {
    string allocated_name = get_string("What's your name?", 32);
    if (errno != 0) {
      return errno;
    }
    name = allocated_name;
  } else if (argc == 2) {
    name = argv[1];
  } else {
    println("This program doesn't need so much arguments!");
    return 1;
  }

  if (strlen(name) == 0) {
    println("Your name is empty...");
    free(name);
    return 1;
  }

  println("Your name is %s!!!", name);

  free(allocated_name);

  return 0;
}

int game2(void) {

  int number = get_int("Type a number!", 32);

  if (errno != 0) {
    return errno;
  }

  println("You just typed %i!", number);

  return 0;
}

int game3(void) {
  println("A. Hello World\nB. 1234567890");

  char character = get_char("Choose an option.", 32);

  if (errno != 0) {
    return 0;
  }

  switch (character) {
  case 'a':
  case 'A':
    println("Hello World!");
    break;

  case 'b':
  case 'B':
    println("1234567890");
    break;

  default:
    println("There's no such option!");
    errno = EINVAL;
    break;
  }

  return 0;
}

void test(void) {
  int a = str_to_int("500");

  long b = str_to_long("500");

  long long c = str_to_long_long("500");

  float d = str_to_float("500.0");

  double e = str_to_double("500.0");

  println("a = %i\nb = %i\nc = %i\nd = %f\ne = %f", a, b, c, d, e);
}

int main(int argc, string *argv) {
  test();
  
  game1(argc, argv);

  if (errno != 0) {
    println("An error occured at game1: %s", strerror(errno));
    return 1;
  }

  game2();

  if (errno != 0) {
    println("An error occured at game2: %s", strerror(errno));
    return 1;
  }

  game3();

  if (errno != 0) {
    println("An error occured at game3: %s", strerror(errno));
  }

  return 0;
}
