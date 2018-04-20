#include <stdio.h>
#include "../lib/er.h"
#include "../lib/assert.h"

void print_message(char *message) {
  printf(message);
}

int main(void) {
  assert_equals(print_message,
		"Testing mail-from regex",		
		"username@gmail.com",
		mail_from("--mail-from username@gmail.com"));
    assert_equals(print_message,
		"Testing mail-rcpt regex",		
		"username@gmail.com",
		mail_from("--mail-rcpt username@gmail.com"));
}
