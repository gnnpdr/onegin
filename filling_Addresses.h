#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "filling_Data.h"

struct Array
{
    char** addresses;  
    int amount_of_strings;
};

void processing_text(Data* original_text, Array* text_for_sorting);
void filling_addresses(Data* original_text, Array* text_for_sorting);

#endif //ADDRESSES_H