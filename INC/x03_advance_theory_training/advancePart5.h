#include "_x03_include.h"
#ifdef _ADVANCE_PART_5_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <string.h>
#include <tuple>

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

enum errorType_t
{
    ERROR_WRONG_DATA = 0x11U,
    ERROR_SHORT_DATA = 0x22U,
    ERROR_LONG_DATA = 0x33U
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
 * @brief  Returnng multiple values in C++ 
 *          Using tuplets from std
 */
typedef std::tuple<uint32_t, uint32_t, uint64_t, std::string> dataFrameRow_t;
dataFrameRow_t RetTupleFunction(uint8_t inIndex);
void CallRetTupleFunction(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why we need virtual destructor
 * 
 *          To call both destructore from derived class and from base class.
 *          This can lead to memory leak
 */
class BaseVirtualDestructor
{
public:
    virtual void Print(void)                { std::cout << "Base class method - Print " << std::endl; }

    BaseVirtualDestructor(void)             { std::cout << "Base class constructor  "   << std::endl;}
    virtual ~BaseVirtualDestructor(void)    { std::cout << "Base class destructor  "    << std::endl;}
};

class DerivedVirtualDestructor: public BaseVirtualDestructor
{
public:
    virtual void Print(void)                { std::cout << "Derived class method - Print "  << std::endl; }

    DerivedVirtualDestructor(void)          { std::cout << "Derived class constructor  "    << std::endl;}
    ~DerivedVirtualDestructor(void)         { std::cout << "Derived class destructor  "     << std::endl;}
};
void CallVirtualDestructor(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the places where initializer list must be present
 * 
 *          When constatnt is initialized
 *          When reference is initialized
 *          When class is asigning inside class
 */
class BaseListInitializer
{
    const int _X;
    int& refSomeInt;
public:
    BaseListInitializer(int& refSomeInt):           _X(0x00),   refSomeInt(refSomeInt)      { refSomeInt++;}
    BaseListInitializer(int x, int& refSomeInt):    _X(x),      refSomeInt(refSomeInt)      { refSomeInt++;}

    void Print(void) {  std::cout << "_X = " << _X << std::endl; }
};

class DerivedListInitializer: public BaseListInitializer
{
    const int _Y;
public:
    DerivedListInitializer(int y, int x, int& refSomeInt):  BaseListInitializer(x, refSomeInt), _Y(y) 
    {   std::cout << "DerivedListInitializer and BaseListInitializer" << std::endl; }

    void Print(void) 
    {   std::cout << "_Y = " << _Y << std::endl; 
        BaseListInitializer::Print();   }
};
void CallListInitializer(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the drawback of vectors in C++
 *          It overalocated memory which some times could be very bad in terms of performance
 *          When ever capacity of vecors it copy element from previous to new vector 
 */
void CallDrawbackOfVectors(void);// 5,10
//==========================================================================================================

#endif // _ADVANCE_PART_5_H