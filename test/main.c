#include <stdio.h>
#include <string.h>
#include "../lib/er.h"

int main(void)  {
  printf("\n");
  
  printf("Testando regex do parametro mail_from : ");
  if (("usermane@mail.com" == mail_from("--mail-from username@gmail.com")) == 0)
    printf("OK");
  else 
    printf("FAIL");

  printf("\n");  


  printf("Testando regex do parametro mail_rcpt: ");
  if (("usermane@mail.com" == mail_rcpt("--mail-rcpt username@gmail.com")) == 0)
    printf("OK");
  else 
    printf("FAIL");

  printf("\n");  
}
