#include <stdio.h>
#include "test.h"

int main(void)
{
    char h[] = "hello";
    printf("%s\n", h);
    CStrReversal(h);
    printf("%s\n", h);
}