#include "test.h"
#include <string.h>

void CStrReversal(char* str)
{
    long len;
    char temp;
    len = strlen(str);
    for (long i = len - 1; i > (len/2) ; i--)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}