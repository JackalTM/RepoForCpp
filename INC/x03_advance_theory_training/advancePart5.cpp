#include "advancePart5.h"

/***********************************************************************************************************
 * @brief       The differences betwen plain enum and enum class in C++
 * 
 *              Enumarate widhout scope can be problematic coz is mis with diffrent variables
 *      
 *              Enumarate class is much more elagant o use
 */
void CallEnumTypes(void)
{
    normalEnum errorTypes1;
    errorTypes1 = worngData;
    switch (errorTypes1)
    {
    case worngData: std::cout << "normalEnum Wrong data  " <<  errorTypes1 <<   std::endl;      break;
    case shortData: std::cout << "normalEnum Short data  " <<  errorTypes1 <<   std::endl;      break;
    case longData:  std::cout << "normalEnum Long data   " <<  errorTypes1 <<   std::endl;      break;
    }

    classEnum errorTypes2;
    errorTypes2 = classEnum::worngData;

    switch (errorTypes2)
    {
    case classEnum::worngData: std::cout << "classEnum Wrong data  " <<  errorTypes1 <<   std::endl;   break;
    case classEnum::shortData: std::cout << "classEnum Short data  " <<  errorTypes1 <<   std::endl;   break;
    case classEnum::longData:  std::cout << "classEnum Long data   " <<  errorTypes1 <<   std::endl;   break;
    }
}// 4,46
//==========================================================================================================