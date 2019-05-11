#include <stdio.h>
char * strip(char *s) {
    int i=0;
    char *p=s;
    char *q;
    char *f;

    while(*p==' ' || *p== '\n' || *p=='\t') {
        p++;
    }
    if(p>s) {
        q=s;
        while(*p!= '\0') {
            *q++=*p++;
        }
        *q='\0';
    }
    f=s;
    while(*(f)!='\0'){
        f++;
    }
   f--;
    
    while(*(f)== ' ' || *(f)=='\t' || *(f)=='\n'){
        f--;
    
    }
    *(f)='\0';
    return s;
}
