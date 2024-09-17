#ifndef REV_SORT_H
#define REV_SORT_H

#include "forward_sort.h"

void reverse_sorting(Array* text_for_sorting);
int reverse_comparing(Array* text_for_sorting, int string, int element);
void rev_swap_str(Array* text_for_sorting, int string);
void reverse_finding_start_address(char** address_str); 

#endif //REV_SORT_H