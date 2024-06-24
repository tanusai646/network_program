#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "abc", *sp = "abc";
    printf("s[] = %s, sp = %s\n", s, sp);

    strcpy(s, "123");

    sp = "vwxyz";

    printf("s[] = %s, sp = %s\n", s, sp);
}