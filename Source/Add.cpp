#include "../Include/Add.h"
#include <stdio.h>

Add::Add(uint32_t num1, uint32_t num2) :
    _num1(num1),
    _num2(num2)
{
}

void Add::DispalySum()
{
    printf("The Sum Of %d + %d = %d\n", _num1, _num2, _num1 + _num2);
}