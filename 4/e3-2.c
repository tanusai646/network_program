#include <stdio.h>
#include <stdlib.h>

struct student{
    char id[10];
    int score;
};

int main(void){
    struct student seito[10];
    int i = 0;
    FILE *fin, *fout;
    fin = fopen("input2.dat", "r");
    fout = fopen("output2.dat", "w");

    int allscore = 0;
    int allcount = 0;
    double ave = 0;

    if(fin == NULL){
        printf("No file\n");
        exit(1);
    } else {
        while(feof(fin) == 0){
            fscanf(fin,"%s %d\n",seito[i].id, &seito[i].score); // ファイル入出力
            allscore = allscore + seito[i].score;
            //printf("%d\n", seito[i].score);
            i++;
        }
        ave = allscore / i;

        fprintf(fout,"学生数 = %d\n平均点 = %f\n",i, ave);

    }

    fclose(fin);
    fclose(fout);

    return 0;
}
