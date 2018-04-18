#include <stdio.h>
#include <string.h>
#include "pcre.h"
#include "er.h"

char *mail_rcpt(char *args) {
  int ovector[100];
  pcre *re;
  char *regex = "(?<=--mail-rcpt)(?: +)[a-z@\\.]+";
  int rc;

  re = pcre_compile(regex,
		    PCRE_MULTILINE,
		    NULL,
		    NULL,
		    0);

  if (re == NULL)
     return "FAIL";
  
rc = pcre_exec(
  re,                   /* the compiled pattern */
  NULL,                 /* no extra data - we didn't study the pattern */
  args,              /* the subject string */
  strlen(args),      /* the length of the subject */
  0,                 /* start at offset 0 in the subject */
  0,                    /* default options */
  ovector,              /* output vector for substring information */
  100);           /* number of elements in the output vector */

 pcre_free(re);
 
 if(rc < 0)
    return "FAIL";
 else 
    return args + ovector[0];  
}

char *mail_from(char *args) {
  int ovector[100];
  pcre *re;
  char *regex = "(?<=--mail-from)(?: +)[a-z@\\.]+";
  int rc;

  re = pcre_compile(regex,
		    PCRE_MULTILINE,
		    NULL,
		    NULL,
		    0);

  if (re == NULL)
     return "FAIL";
  
rc = pcre_exec(
  re,                   /* the compiled pattern */
  NULL,                 /* no extra data - we didn't study the pattern */
  args,              /* the subject string */
  strlen(args),      /* the length of the subject */
  0,                 /* start at offset 0 in the subject */
  0,                    /* default options */
  ovector,              /* output vector for substring information */
  100);           /* number of elements in the output vector */

 pcre_free(re);
 
 if(rc < 0)
    return "FAIL";
 else 
    return args + ovector[0];
}
