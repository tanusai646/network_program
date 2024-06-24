#include <stdio.h>
int main(){
    char c, *cp;
    int i, *ip;
    double d, *dp;

    cp = &c;
    printf("cp = %p, cp + 1 = %p, cp + 2 = %p\n", cp, cp+1, cp+2);

    ip = &i;
    printf("ip = %p, ip + 1 = %p, ip + 2 = %p\n", ip, ip+1, ip+2);

    dp = &d;
    printf("dp = %p, dp + 1 = %p, dp + 2 = %p\n", dp, dp+1, dp+2);
}