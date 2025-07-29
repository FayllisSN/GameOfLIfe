#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cell_area_func.h"

int main(void)
{
    srand(time(NULL));
    init_area();    
    int celAm = cell_inputAmount();
    cell_inputMode(celAm);
    while(1){
        draw_frame();
        cell_Statuscheck();
        if(cell_AmountCheck() == 0) {
            printf("ALL LIFE DIED");       
            break;
        }
    }
    return 0;
}
