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
typedef std::tuple<int, int> bothVals_tuple;
class BaseListInitializer
{
    const int _X;
    int& refSomeInt;
public:
    BaseListInitializer(int& refSomeInt):           _X(0x00),   refSomeInt(refSomeInt)      { refSomeInt++;}
    BaseListInitializer(int x, int& refSomeInt):    _X(x),      refSomeInt(refSomeInt)      { refSomeInt++;}

    int GetValue(void)  { return _X; }
    void Print(void) {  std::cout << "_X = " << _X << std::endl; }
};

class DerivedListInitializer: public BaseListInitializer
{
    const int _Y;
public:
    DerivedListInitializer(int y, int x, int& refSomeInt):  BaseListInitializer(x, refSomeInt), _Y(y) 
    {   std::cout << "DerivedListInitializer and BaseListInitializer" << std::endl; }

    int GetValue(void)  { return _Y; }
    bothVals_tuple GetBothValues(void) { return std::make_tuple( _Y, BaseListInitializer::GetValue()); }

    void Print(void) 
    {   std::cout << "_Y = " << _Y << std::endl; }

    void PrintBoth(void)    
    {   Print(); 
        BaseListInitializer::Print(); }
};
void CallListInitializer(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the drawback of vectors in C++
 *          It overalocated memory which some times could be very bad in terms of performance
 *          When ever capacity of vecors it copy element from previous to new vector 
 */
void CallDrawbackOfVectors(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is Constructor Delegation in C++
 * 
 *          Constructior is delegated to bottom constructor
 *          If the constructor has heavy code inside to prevent code bloating constructor is delegated to main one
 */
class BaseConstrDelegation
{
    int _x, _y;
    int _xy;

public:
    // Both delegated constructors
    BaseConstrDelegation(void):             BaseConstrDelegation(0, 0) {;}
    BaseConstrDelegation(int x):            BaseConstrDelegation(x, 0) {;}
    // True constructor
    BaseConstrDelegation(int x, int y):     _x(x), _y(y) 
    {//  Example of some inside calculation that are present.
        int temp = 1;
        temp = (x << 2) + temp;
        temp = (y << 2) + temp;
        _xy = temp;
    }

    void Print(void)    
    {   std::cout << " _x= " << _x << "_y= " << _y << std::endl; 
        std::cout << " resould of _xy= "     << _xy << std::endl;  }
};
void CallDelegationCOnstruction(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What does the printf and scanf function returns?
 * 
 *          printf returns number of characters printed succesfuly 
 *          scanf returns the number of elements read successfully from console
 */
void CallTestPrintfScanf(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is RVO and NRVO in C++?
 * 
 *          It stands for return value optimazition and named return value optimazition
 */
class Base_RVO_NRVO
{
    int X;
public:
    Base_RVO_NRVO(void) 
    {   std::cout << "Constructor: Base_RVO_NRVO " << std::endl;    }

    Base_RVO_NRVO(const Base_RVO_NRVO &) 
    {   std::cout << "Copy Constructor: Base_RVO_NRVO " << std::endl;    }
};
Base_RVO_NRVO FunctionOf_RVO_NRVO(void);

void Call_RVO_NRVO(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the best place to use enum in C++
 *          
 *          Enum is used in some limited sets of values
 *          Function can take one values from set like parameter input
 */
enum class MAIN_COLORS { RED = 0x11U, GRN = 0x22U, BLU = 0x33U };
void CallEnumTestFunc(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the diffrence between struct and class in C++
 *  
 *          Class memebers are private by dafault
 *          Struct memebers are public by default
 */
class classBaseType
{// Default it is private
    int x;
    int y;
    int z;
};

class classDrivedType: classBaseType
{// Default it is private
    int a;
    int b;
    int c;
};

struct structBaseType
{// Default it is public
    int x;
    int y;
    int z;
};
struct structDerivedType: structBaseType
{// Default it is public
    int a;
    int b;
    int c;
};

void Call_classTestType_structTestType(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the order of functionevaluation in C++
 *  5,32
 */

//==========================================================================================================

#endif // _ADVANCE_PART_5_H