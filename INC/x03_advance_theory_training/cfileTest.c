#include "cfileTest.h"
#ifdef _CFILE_TEST_H

uint8_t FuncfileTestLogicAND(uint8_t inA, uint8_t inB)
{
    return (inA & inB);
}
uint8_t FuncfileTestLogicOR(uint8_t inA, uint8_t inB)
{
    return (inA | inB);
}
#endif // _CFILE_TEST_H