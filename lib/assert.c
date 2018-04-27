#include <string.h>

int assert_equals(void (*printer)(char *), char *test_message, char *first_value, char *second_value) {
  (*printer)(test_message);
  if (strcmp(first_value, second_value) == 0) {
    (*printer)(" OK\n");
    return 0;
  }
  else {
    (*printer)(" OK\n");   
    return 1;
  }  
}
