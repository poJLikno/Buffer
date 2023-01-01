#include "num_converter.h"

int bin_to_dec(char *str)
{
    int length = 0;
    int res = 0;
    
    while (str[length] != '\0') length++;
    
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '1')
            res += (int)pow(2, length - 1 - i);
    }
    
    return res;
}

int bin_to_dec(string str)
{
    int res = 0;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
            res += (int)pow(2, str.length() - 1 - i);
    }
    
    return res;
}
