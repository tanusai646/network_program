//演習１
#include <stdio.h>

int fact(int x){ // 関数 fact()の定義
    if (x==1) return 1; // ～ 「再帰」の利用
    else return x * fact(x-1);
}

int main(){
    int x;
    do{
        scanf("%d",&x); // キーボード入力
        printf("%d! = %d\n",x, fact(x));
    }while(x <= 10); // ディスプレイ出力
}