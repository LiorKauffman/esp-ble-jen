#ifndef _ADD_H
#define _ADD_H

#include <stdint.h>

class Add
{
private:
    /* data */
    uint32_t _num1;
    uint32_t _num2;
public:
    Add(uint32_t num1, uint32_t num2);
    void DispalySum();

};

#endif