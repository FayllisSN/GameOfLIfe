#include <stdio.h>
#define width 24
#define height 12
int gameMatrix[height][width];

int main(void)
{
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            gameMatrix[i][j] = ' ';
            if(i == 0 || i == height - 1) gameMatrix[i][j] = '_';
            if((j == 0 || j == width - 1) && i != 0) gameMatrix[i][j] = '|';
            printf("%c",gameMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}