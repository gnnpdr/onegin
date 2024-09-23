#include <stdio.h>

#include "filling_Data.h"
#include "filling_Addresses.h"
#include "print.h"
#include "sorting.h"
#include "free.h"

int main()
{
    bool right_enter = true;

    int opening_cnt = 0;
    int cnt = 0;
    

    //printf("main opening %d, cnt %d\n", opening_cnt, cnt);

    Data original_text = {};
    Array text_for_sorting = {};

    filling_Data(&original_text, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem\n");
        return 1;
    }
    
    processing_text(&original_text, &text_for_sorting); //надо засунуть эту функцию и слудующую в какую-то одну, занимающуюся этой структурой.
    filling_addresses(&original_text, &text_for_sorting, &right_enter);
    if (right_enter == false)
    {
        printf("there is problem\n");
        return 1;
    }

    //print_text(&text_for_sorting);
    //printf("\n");

    //forward_sorting(&text_for_sorting);
    sorting(forward_comparing, &text_for_sorting);
    print_text(&text_for_sorting, &opening_cnt, &cnt, &right_enter);
    //printf("main first run opening %d, cnt %d\n", opening_cnt, cnt);

    //reverse_sorting(&text_for_sorting);
    sorting(reverse_comparing, &text_for_sorting);
    print_text(&text_for_sorting, &opening_cnt, &cnt, &right_enter);
    //printf("main sec run opening %d, cnt %d\n", opening_cnt, cnt);

    free_arrays(&text_for_sorting, &original_text);

    printf("oh no, here we go again\n");

    return 0;
}

