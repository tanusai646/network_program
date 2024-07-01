#include <stdio.h>
#include <stdlib.h>

//構造体の作成
struct student{
    char id[10];
    int score;
};

int main(void){
    struct student seito[10];
    int i = 0;
    FILE *fin, *fout;
    fin = fopen("input2.dat", "r");     //input2.datを読み込み専用で開く
    fout = fopen("output2.dat", "w");   //output2.datを書き込み専用で開く

    int allscore = 0;                   //合計点用
    double ave = 0;                     //平均点用

    if(fin == NULL){
        printf("No file\n");
        exit(1);
    } else {
        while(feof(fin) == 0){
            fscanf(fin,"%s %d\n",seito[i].id, &seito[i].score); // ファイル入出力
            allscore = allscore + seito[i].score;
            i++;
        }
        ave = allscore / i;
        fprintf(fout,"学生数 = %d\n平均点 = %f\n",i, ave);
    }

    fclose(fin);                        //fileクローズ
    fclose(fout);

    return 0;
}
