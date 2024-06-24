#include <stdio.h>

int fact(int x){
    if (x==1) return 1;
    else return x * fact(x-1);
}

int main(){
    int x;
    FILE *fin, *fout; // ファイルポインタを定義
    fin = fopen("input1.dat", "r"); // 入力ファイル
    fout = fopen("output1.dat","w"); // 出力ファイル
    do{
        fscanf(fin,"%d\n",&x); // ファイル入出力
        fprintf(fout,"%d! = %d\n",x, fact(x));
    }while(feof(fin) == 0); // ～終了まで繰返
    fclose(fin); 
    fclose(fout);
}