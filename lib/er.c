#include <string.h>
#include "pcre.h"

char *get_arg(char *args, char *arg_name) {
  int ovector[100];
  pcre *re; 
  char regex[100] = "(?<=--";
  char dest[50];
  strcpy(dest, arg_name);
  strcat(regex, dest);
  strcat(regex, ")(?: +)[^ ]+\b");
  
  int rc;

  re = pcre_compile(regex,
		    PCRE_MULTILINE,
		    NULL,
		    NULL,
		    0);

  if (re == NULL) {
    return "FAIL";
  } 
  
rc = pcre_exec(
  re,                   /* the compiled pattern */
  NULL,                 /* no extra data - we didn't study the pattern */
  args,                 /* the subject string */
  strlen(args),         /* the length of the subject */
  0,                    /* start at offset 0 in the subject */
  0,                    /* default options */
  ovector,              /* output vector for substring information */
  100);                 /* number of elements in the output vector */

 pcre_free(re);
 
 if(rc < 0)
    return "FAIL";
 else 
    return args + ovector[0];  
}

char *mail_from(char *args) {
  return get_arg(args, "mail-from"); 
}

char *mail_rcpt(char *args) {
  return get_arg(args, "mail-rcpt");
}
