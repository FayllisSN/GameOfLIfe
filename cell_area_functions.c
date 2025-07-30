#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#define width 56
#define height 28
int gameMatrix[height][width];
int cellsLimits = (width - 2) * (height - 2);
int cellCount = 0;
void init_area()
{
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            gameMatrix[i][j] = ' ';
            if(i == 0 || i == height - 1) gameMatrix[i][j] = '_';
            if((j == 0 || j == width - 1) && i != 0) gameMatrix[i][j] = '|';
        }
    }
}
int cell_inputAmount()
{
    int flag = 1,n;
    while(flag){
        printf("Enter an amount of cells you want to place. Not above(%d)\n",cellsLimits);
        scanf("%d",&n);
        if(n > cellsLimits || n < 0){
            printf("Not in the limits\n");
            continue;
        }
        flag = 0;
    }
    return n;
}
void cell_inputMode(int celAm)
{
    int mode,count = 0,celX,celY;
    while(1){
        printf("Choose input mode\n1.By yourself\n2.Random\n");
        scanf("%d",&mode);
        if(mode > 2 || mode < 1){
            printf("Wrong mode input");
            continue;
        }
        if(mode == 1){
            while(count++ < celAm){
                printf("Input X betwen(1,%d) and Y betwen(1,%d) for cell №[%d]\n",width - 2,height - 2,count);
                scanf("%d %d",&celX,&celY);
                gameMatrix[celY][celX] = '#';
            }
        }
        if(mode == 2){
            while(count < celAm){
                celY = rand() % (height - 2) + 1;
                celX = rand() % (width - 2) + 1;
                if(gameMatrix[celY][celX] == '#') continue;
                gameMatrix[celY][celX] = '#';
                count++;    
            }
        }
        break;
    }
    system("cls");
}
void draw_frame()
{
    for(int i = 0;i < height;i++){
        //printf("                                            ");
        for(int j = 0;j < width;j++){
            if(j == 0 && i == 0){ 
                printf("\u2554");
                continue;
            }
            if(j == width - 1 && i == height - 1){ 
                printf("\u255D");
                continue;
            }
            if(j == width - 1 && i == 0){ 
                printf("\u2557");
                continue;
            }
            if(j == 0 && i == height - 1){ 
                printf("\u255A");
                continue;
            }
            if(gameMatrix[i][j] == '_'){ 
                printf("\u2550");
                continue;
            }
            if(gameMatrix[i][j] == '|'){ 
                printf("\u2551");
                continue;
            }
            printf(" ");
        }
        printf("\n");
    }
    Sleep(100);
    //system("cls");
}
void cell_Statuscheck()
{
    for(int i = 1;i < height - 1;i++){
        for(int j = 1;j < width - 1;j++){
            cellCount = 0;
            if(gameMatrix[i][j] == ' '){
                for(int k = i - 1;k <= i + 1;k++){
                    for(int l = j - 1;l <= j + 1;l++){
                        if((k == i && l == j)) continue;
                        if(gameMatrix[k][l] == '#' || gameMatrix[k][l] == '*') cellCount++;
                    }
                }
                if(cellCount == 3){
                    gameMatrix[i][j] = '.';
                }
                continue;
            }
            if(gameMatrix[i][j] == '#'){
                for(int k = i - 1;k <= i + 1;k++){
                    for(int l = j - 1;l <= j + 1;l++){
                        if(k == i && l == j) continue;
                        if(gameMatrix[k][l] == '#' || gameMatrix[k][l] == '*') cellCount++;
                    }
                }
                if(cellCount < 2 || cellCount > 3){
                    gameMatrix[i][j] = '*';
                } 
            }
        }
    }
    for(int i = 1;i < height - 1;i++){
        for(int j = 1;j < width - 1;j++){
            if(gameMatrix[i][j] == '*'){ 
                gameMatrix[i][j] = ' ';
                printf("\x1b[%d;%df", i + 1, j + 1);
                printf("%c",gameMatrix[i][j] = ' ');
            }
            if(gameMatrix[i][j] == '.' || gameMatrix[i][j] == '#'){ 
                gameMatrix[i][j] = '#';
                printf("\x1b[%d;%df", i + 1, j + 1);
                printf("%c",gameMatrix[i][j] = '#');
            }
        }
    }
}
int cell_AmountCheck()
{
    cellCount = 0;
    for(int i = 1;i < height - 1;i++){
        for(int j = 1;j < width - 1;j++){
            if(gameMatrix[i][j] == '#') cellCount++;
        }
    }
    return cellCount;
}