#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
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
                printf("Input X betwen(1,54) and Y betwen(1,26) for cell №[%d]\n",count);
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
        break;
    }
    system("cls");
}
void draw_frame()
{
    for(int i = 0;i < height;i++){
        printf("                                            ");
        for(int j = 0;j < width;j++){
            printf("%c",gameMatrix[i][j]);
        }
        printf("\n");
    }
    Sleep(700);
    system("cls");
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
            if(gameMatrix[i][j] == '*') gameMatrix[i][j] = ' ';
            if(gameMatrix[i][j] == '.') gameMatrix[i][j] = '#';
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
int main(void)
{
    srand(time(NULL));
    init_area();    
    int celAm = cell_inputAmount();
    cell_inputMode(celAm);
    while(1){
        draw_frame();
        cell_Statuscheck();
        if(cell_AmountCheck() == 0) break;;
    }
    printf("ALL LIFE DIED");
    return 0;
}
