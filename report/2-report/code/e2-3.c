#include <stdio.h>
#include <stdlib.h>

void slink(char *s, char *s1, char *s2){
    int i = 0;
    while(*s1 != '\0'){
        s[i] = *s1;
        i++;
        s1++;
    }
    s[i] = '_';
    i++;
    while(*s2 != '\0'){
        s[i] = *s2;
        i++;
        s2++; 
    }
    s[i] = '\0';
}

int main(int argc, char *argv[]){
    char s[30], s1[] = "Kawahara", s2[] = "Kenji";
    slink(s,s1,s2);
    printf("%s\n", s);
}