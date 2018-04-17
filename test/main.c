#include <stdio.h>
#include <string.h>
#include "../lib/er.h"

int main(void)  {
  // Apenas para melhorar a visualizacao
  printf("\n");
  
  printf("Testando regex do parametro mail_from : ");
  if (strcmp("usermane@mail.com", mail_from("--mail-from  username@mail.com")) == 0)
    printf("OK");
  else 
    printf("FALHA");

  // Apenas para melhorar a visualizacao
  printf("\n\n");
}
