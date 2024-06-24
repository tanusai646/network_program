#include <stdio.h>
#include <stdlib.h>

void slink(char *s, char *s1, char *s2){
    sprintf(s, "%s_%s\n", s1, s2);
}

int main(int argc, char *argv[]){
    char s[30];
    slink(s,argv[1],argv[2]);
    printf("%s\n", s);
}