#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include "cell_area_func.h"
int intervalTime,generation = 0;
int main(void)
{
    srand(time(NULL));
    init_area();    
    int celAm = cell_inputAmount();
    printf("Interval between frames\n"); 
    scanf("%d",&intervalTime);
    cell_inputMode(celAm);
    //printf("\e[?25l");
    draw_frame();
    while(1){
        cell_Statuscheck();
        Sleep(intervalTime);
        if(cell_AmountCheck() == 0) {
            printf("\x1b[%d;%df", 1, 1);
            printf("ALL LIFE DIED\nAmount of generations:[%d]",++generation);       
            break;
        }
        generation++;
    }
    return 0;
}
