#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <string.h>

/***********************************************************************************************************
 * @brief       The differences betwen plain enum and enum class in C++
 * 
 */
enum normalEnum
{
    worngData = 0x11U,
    shortData = 0x22U,
    longData = 0x33U
};


enum class classEnum
{
    worngData = 0x11U,
    shortData = 0x22U,
    longData = 0x33U
};


void CallEnumTypes(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   
 * 
 */

//==========================================================================================================