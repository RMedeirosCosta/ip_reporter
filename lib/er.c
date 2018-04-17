#include <stdio.h>
#include <string.h>
#include "er.h"

char *mail_from(char *args) {
  
  if(strcmp("teste", args) == 0)
    return "ok";  
  else 
    return "error";
}
