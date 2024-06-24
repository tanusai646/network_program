#include <stdio.h>

int main(){
    char s[20];
    char *cp = "Kyutech";
    int i = 0;

    while(*cp != '\0'){
        s[i] = *cp;
        i++;
        cp++;
    }
    s[i] = '\0';
    printf("%s\n", s);
}