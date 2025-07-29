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
    printf("Interval between\n"); 
    scanf("%d",&intervalTime);
    printf("\e[?25l");
    cell_inputMode(celAm);
    draw_frame();
    while(1){
        cell_Statuscheck();
        Sleep(intervalTime);
        if(cell_AmountCheck() == 0) {
            printf("\x1b[%d;%df", 1, 1);
            draw_frame();
            printf("ALL LIFE DIED\nAmount of generations:[%d]",++generation);       
            break;
        }
        generation++;
    }
    return 0;
}
