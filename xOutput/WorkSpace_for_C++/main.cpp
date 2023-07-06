#include <stdio.h>
#include <stdint.h>
#include "INC/x02_InheritanceTest/InheritanceTest.h"

#define INT32MAX (uint32_t)(-1)
Children_class InheritanceTest(0xAA, INT32MAX);

int main()
{
    InheritanceTest.PrintAdd(0xFF, 0xFF);
    InheritanceTest.PrintSubb(0xFF, 0xFF);
    InheritanceTest.PrintMull(0xFF, 0xFF);
    InheritanceTest.PrintDive(0xFF, 0xFF);
    InheritanceTest.PrintAND(0xF0, 0x0F);
    InheritanceTest.PrintOR(0xF0, 0x0F);
    InheritanceTest.PrintAll(INT32MAX, INT32MAX);
    InheritanceTest.PrintLastOperations();

    return 0;
}