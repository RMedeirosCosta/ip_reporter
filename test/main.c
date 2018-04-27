#include <stdio.h>
#include "../lib/er.h"
#include "../lib/assert.h"

void print_message(char *message) {
  printf(message);
}

void print_space() {
  printf("\n");
}

int main(void) {
  // Testing empty arguments
  assert_equals(print_message,
      "Testing mail_from empty",		
      "",
      mail_from("--mail-from "));
  assert_equals(print_message,
      "Testing mail-rctp empty",		
      "",
      mail_from("--mail-rcpt "));
  assert_equals(print_message,
      "Testing password empty",		
      "",
      mail_from("--password "));
  
  print_space();

  // All arguments
  assert_equals(print_message,
      "Testing mail-from regex with all arguments",		
      "username@gmail.com",
      mail_from("--mail-from username@gmail.com --mail-rcpt another_email@gmail.com --password my_password_key"));
  assert_equals(print_message,
      "Testing mail-rcpt regex with all arguments",		
      "username@gmail.com",
      mail_rcpt("--mail-from another_email@gmail.com --mail-rcpt username@gmail.com --password my_password_key"));
  assert_equals(print_message,
      "Testing password regex with all arguments",
      "username@gmail.com",
      password("--mail-from another_email@gmail.com --mail-rcpt username@gmail.com --password my_password_key"));
  
  print_space();

  // Testing with some arguments
  assert_equals(print_message,
      "Testing mail-from regex with some arguments",
      "username@gmail.com",
      mail_from("--mail-from username@gmail.com"));
  assert_equals(print_message,
      "Testing mail-rcpt regex with some arguments",		
      "username@gmail.com",
      mail_rcpt("--mail-rcpt username@gmail.com"));
  assert_equals(print_message,
      "Testing password regex with some arguments",
      "username@gmail.com",
      password("--password my_password_key"));

  print_space();

  // Testing with invalid arguments
  assert_equals(print_message,
      "Testing mail-from regex with invalid arguments",		
      "",
      mail_from("--mail-from uzumaki_naruto dattebayo!"));
  assert_equals(print_message,
      "Testing mail-rcpt regex with invalid arguments",		
      "",
      mail_rcpt("--mail-rcpt sasuke uchiha_the_sharingan user"));
}
