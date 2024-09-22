#include <stdio.h>

#include "reverse_sort.h"

void reverse_finding_start_address(char** address_str)
{
    assert(address_str != nullptr);

    while (isalpha(**address_str) == 0)
        *address_str = *address_str - sizeof(char);
}

int reverse_comparing(char* string1, char* string2)
{
    assert(string1 != nullptr);
    assert(string2 != nullptr);

    reverse_finding_start_address(&string1); 
    reverse_finding_start_address(&string2);

    if (tolower(*string1) == tolower(*string2))
    {
        while(tolower(*string1) == tolower(*string2))
        {
            string1--;
            string2--;
        }
    }

    if (tolower(*string1) > tolower(*string2))
        return GREATER;
}

void reverse_sorting(Array* const text_for_sorting) 
{
    assert(text_for_sorting != nullptr);

    for (int max_str = text_for_sorting->amount_of_strings - 1; max_str > 0; max_str--)
    {
        for (int string_index = 0; string_index < max_str; string_index++)
        {
            char* string1 = text_for_sorting->addresses[string_index].end;
            char* string2 = text_for_sorting->addresses[string_index + 1].end;

            int difference = reverse_comparing(string1, string2);

            if (difference == GREATER)
            {
                struct StringParametres string_1 = {};
                struct StringParametres string_2 = {};

                string_1 = text_for_sorting->addresses[string_index];
                string_2 = text_for_sorting->addresses[string_index + 1];

                swap(&string_1, &string_2);

                text_for_sorting->addresses[string_index] = string_1;
                text_for_sorting->addresses[string_index + 1] = string_2;
            }
        }
    }
}