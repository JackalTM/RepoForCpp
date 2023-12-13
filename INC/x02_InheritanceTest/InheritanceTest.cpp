#include "InheritanceTest.h"
#ifdef CMP_X02_INHERITANCE_TEST_H

/************************************************************************************
 * @name    Parrent_class
 * @brief   Class Contruktor
 * @param   initVal Initial value for private data
*/
Parrent_class::Parrent_class(uint32_t initVal)
{
    lastAdd = initVal;
    lastSubb = initVal - 1;
    lastMull = initVal - 2;
    lastDiv = initVal - 3;
}
//===================================================================================

/************************************************************************************
 * @name    Parrent_class
 * @brief   Class deconstruktor
*/
Parrent_class::~Parrent_class()
{
    ;
}
//===================================================================================

/************************************************************************************
 * @name    Add
 * @brief   Return summ from two varibles
 * @param   inA argument A
 * @param   inB argument B
 * @return  Summ of two arguments
*/
uint32_t Parrent_class::Add(uint32_t inA, uint32_t inB)
{
    lastAdd = inA + inB;
    return lastAdd;
}
//===================================================================================

/************************************************************************************
 * @name    Subb
 * @brief   Return subtraction from two varibles
 * @param   inA argument A
 * @param   inB argument B
 * @return  Subtraction of two arguments
*/
uint32_t Parrent_class::Subb(uint32_t inA, uint32_t inB)
{
    lastSubb = inA - inB;
    return lastSubb;
}
//===================================================================================

/************************************************************************************
 * @name    Mull
 * @brief   Return multiplication of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Multiplication of two arguments
*/
uint32_t Parrent_class::Mull(uint32_t inA, uint32_t inB)
{
    lastMull = inA * inB;
    return lastMull;
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Return division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Division of two arguments
*/
uint32_t Parrent_class::Dive(uint32_t inA, uint32_t inB)
{
    lastDiv = inA / inB;
    return lastDiv;
}
//===================================================================================

/************************************************************************************
 * @name    BoolAND
 * @brief   Logical and between arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Resoult of logical and.
*/
uint32_t Parrent_class::BoolAND(uint32_t inA, uint32_t inB)
{
    lastAND = inA & inB;
    return lastAND;
}
//===================================================================================

/************************************************************************************
 * @name    BoolOR
 * @brief   Logical or between arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  Resoult of logical or.
*/
uint32_t Parrent_class::BoolOR(uint32_t inA, uint32_t inB)
{
    lastOR = inA | inB;
    return lastOR;
}
//===================================================================================

/************************************************************************************
 * @name    GetLastVals
 * @brief   Return division of two arguments
 * @param   pAdd Pointer to last summ variable
 * @param   pSubb Pointer to last sub variable
 * @param   pMull Pointer to last mull variable
 * @param   pDiv Pointer to last Div variable
 * @return  void
*/
void Parrent_class::GetLastVals(uint32_t* pAdd, uint32_t* pSubb, uint32_t* pMull, uint32_t* pDiv, uint32_t* pAnd, uint32_t* pOr)
{
    *pAdd = lastAdd;
    *pSubb = lastSubb;
    *pMull = lastMull;
    *pDiv = lastDiv;
    *pAnd = lastAND;
    *pOr = lastOR;
}
//===================================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/************************************************************************************
 * @name    Children_class
 * @brief   Class Contruktor
 * @param   initValtoPrint Initial value for private data
 * @param   initvalForLast Initial value for last data 
*/
Children_class::Children_class(uint32_t initValtoPrint, uint32_t initvalForLast):
    Parrent_class(initvalForLast)
{
    valueToPrint = initValtoPrint;   
}
//===================================================================================

/************************************************************************************
 * @name    Children_class
 * @brief   Class Deconstrutor
*/
Children_class::~Children_class()
{;}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAdd(uint32_t inA, uint32_t inB)
{
    retVals[0] = Add(inA, inB);
    printf("RES: 0x%x + 0x%x = 0x%x \n", inA, inB, retVals[0]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintSubb(uint32_t inA, uint32_t inB)
{
    retVals[1] = Subb(inA, inB);
    printf("RES: 0x%x - 0x%x = 0x%x \n", inA, inB, retVals[1]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintMull(uint32_t inA, uint32_t inB)
{
    retVals[2] = Mull(inA, inB);
    printf("RES: 0x%x * 0x%x = 0x%x \n", inA, inB, retVals[2]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintDive(uint32_t inA, uint32_t inB)
{
    retVals[3] = Dive(inA, inB);
    printf("RES: 0x%x / 0x%x = 0x%x \n", inA, inB, retVals[3]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAND(uint32_t inA, uint32_t inB)
{
    retVals[4] = BoolAND(inA, inB);
    printf("RES: 0x%x & 0x%x = 0x%x \n", inA, inB, retVals[4]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintOR(uint32_t inA, uint32_t inB)
{
    retVals[5] = BoolOR(inA, inB);
    printf("RES: 0x%x | 0x%x = 0x%x \n", inA, inB, retVals[5]);
}
//===================================================================================

/************************************************************************************
 * @name    Dive
 * @brief   Print division of two arguments
 * @param   inA argument A
 * @param   inB argument B
 * @return  void
*/
void Children_class::PrintAll(uint32_t inA, uint32_t inB)
{
    PrintAdd(inA, inB);
    PrintSubb(inA, inB);
    PrintMull(inA, inB);
    PrintDive(inA, inB);
    PrintAND(inA, inB);
    PrintOR(inA, inB);
}
//===================================================================================


/************************************************************************************
 * @name    PrintLastOperations 
 * @brief   Print last operations from parent class
 * @param   void
 * @return  void
*/
void Children_class::PrintLastOperations(void)
{
    GetLastVals((uint32_t*)&retVals[0], (uint32_t*)&retVals[1], (uint32_t*)&retVals[2], (uint32_t*)&retVals[3], (uint32_t*)&retVals[4], (uint32_t*)&retVals[5]);
    printf("\nCurrent last operation values: \n");
    printf(" last '+' %x \n", retVals[0]);
    printf(" last '-' %x \n", retVals[1]);
    printf(" last '*' %x \n", retVals[2]);
    printf(" last '/' %x \n", retVals[3]);
    printf(" last '&' %x \n", retVals[4]);
    printf(" last '|' %x \n", retVals[5]);
}

#endif // CMP_X02_INHERITANCE_TEST_H