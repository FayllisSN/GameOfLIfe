#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define width 56
#define height 28
int gameMatrix[height][width];
int cellsLimits = (width - 2) * (height - 2);
int main(void)
{
    srand(time(NULL));
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            gameMatrix[i][j] = ' ';
            if(i == 0 || i == height - 1) gameMatrix[i][j] = '_';
            if((j == 0 || j == width - 1) && i != 0) gameMatrix[i][j] = '|';
        }
    }
// Cells enter    
    printf("Enter an amount of cells you want to place\n");
    srand(time(NULL));
    int celAm = 0;
    scanf("%d",&celAm);
    int mode,count = 0,celX,celY;
    printf("Choose input mode\n1.By yourself\n2.Random\n");
    scanf("%d",&mode);
    if(mode == 1){
        while(count++ < celAm){
            printf("Input X betwen(1,55) and Y betwen(1,27) for cell №[%d]\n",count);
            scanf("%d %d",&celX,&celY);
            gameMatrix[celY][celX] = '#';
        }
    }
    if(mode == 2){
        while(count < celAm){
            celY = rand() % 26 + 1;
            celX = rand() % 54 + 1;
            if(gameMatrix[celY][celX] == '#') continue;
            gameMatrix[celY][celX] = '#';
            count++;
        }
    }
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            printf("%c",gameMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
