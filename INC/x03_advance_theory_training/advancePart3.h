#include "_x03_include.h"
#ifdef _ADVANCE_PART_3_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>

/***********************************************************************************************************
 * @brief   Static variables in classes 
 *          
 */
template<typename T>
class PrintClass
{
private:
    int x;
public:
    static T var;
    void PrintVal() { std::cout << "var:= " << ++var << std::endl; }
};

template<class T>
T PrintClass<T>::var = 0;

void CallStaticVariablesInclasses(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is this pointer in C++
 *          1. Passed as hidden argument to non static memeber function
 *          2. It a const pointer whitch holds the addr of current object [type*const this]
 *          3. If memeber function is cosnt then, this pointers type becomes [const type * const this]
 */
class BaseClass01
{
private:
    int _x;
public:
    void SetValue(int x);
    // void SetValue(Base* const this, int x);

    int GetValue(void);
    // int GetValue(const Base* const this);
};

void CallClassThisPointer_x01(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to assign any object to premitive data types (uint8_t ... int64_t, float etc)
 *          Then operator uint64_t(...) need to be used and allow conversion
 */
class BaseTypeChange
{
private:
    uint64_t _value;

public:
    BaseTypeChange(void)    {;}
    BaseTypeChange(uint64_t value): _value(value)    {;}

    operator int64_t() const    { return _value; }
};

void CallBaseTypeChange(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to call some function before main()
 * 
 *          With use of global variable or static data memeber of class
 */
// int FunBeforeMain(void)    
// {   std::cout << "FunBeforeMain()" <<  std::endl; 
//     return 0;   }

// class BaseBeforeMain
// {
// public:
//     static int sVaribale;

//     BaseBeforeMain(void)    {FunBeforeMain();}
// };

// BaseBeforeMain  myBaseBeforeMain();
// int BaseBeforeMain::sVaribale = FunBeforeMain();

// int main()
// {
//     std::cout << "main()" <<  std::endl; 
//     return 0;
// }
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to check two diffrent object belong to the same class
 * 
 *          By using typeid
 */
class ClassType_AA
{
private:
    int _a;
public:
    void Print(void){ std::cout << "ClassType_AA" <<  std::endl; }
};

class ClassType_BB
{
private:
    int _b;
public:
    void Print(void){ std::cout << "ClassType_BB" <<  std::endl; }
};

void CallClassTypeChack(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to overload pre and post operator in C++
 * 
 *          
 */
class ClassOverloadElement
{
private:
    int _var;
public:
    ClassOverloadElement(void) {;}
    ClassOverloadElement(int val): _var(val) {;}

    void Print(void) { std::cout << "_var = " << _var <<  std::endl; }

    ClassOverloadElement & operator++(void)// Pre increment
    {    _var++; 
        return *this;}

    ClassOverloadElement operator++(int dummy)// post increment whtn argument is passed
    {   ClassOverloadElement temp = *this;
        ++(*this);
        return temp;}
};

void CallOverloadElement(void);
void CallTestPostAndPreUpdatedValue(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to print smething N times without using loop or recursion in C++
 * 
 *          
 */
class BasePrintNtimes
{
private:
    /* data */
public:
    BasePrintNtimes(void)   { std::cout << "BasePrintNtimes constructor" <<  std::endl;}
};
#define PRINT_N_TIMES   0x08
void CallBasePrintNtimes(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Stop from assign and copy object:
 * 
 *          1. Keep copy constructor and assigment operator as privatein clas
 *          2. Inherit dummy class with private copy constructor and assigment operator
 *          3. Delete copy constructor and assigment operator from class
 */
class BaseStopCopy
{// Method 1
private:
    int _x;

    // Copy constructor as prvate
    BaseStopCopy(const BaseStopCopy& RefBaseStopCopy): _x{RefBaseStopCopy._x}   {}

    // Asign operator private in class
    BaseStopCopy& operator = (const BaseStopCopy& RHS) { _x = RHS._x; return *this;}

public:
    BaseStopCopy(void)          {;}
    BaseStopCopy(int x): _x(x)  {;}
};

class BaseCopy: public BaseStopCopy
{// Method 2
private:
    int _x;
public:
    BaseCopy(void):     _x{0}   {;}
    BaseCopy(int x):    _x{x}   {;}
};

class BaseStopCopyDeleteConstr
{// Method 3
private:
    int _x;

public:
    BaseStopCopyDeleteConstr(void) {;}
    BaseStopCopyDeleteConstr(int x): _x(x) {;}
    
    BaseStopCopyDeleteConstr(const BaseStopCopyDeleteConstr& RefBaseStopCopyDeleteConstr) = delete;
    BaseStopCopyDeleteConstr& operator = (const BaseStopCopyDeleteConstr& RHS) = delete;
};

void CallBaseStopCopy(void);
//==========================================================================================================
// 2,55

/***********************************************************************************************************
 * @brief   Stop from from takig addr of my object
 * 
 *          1. overload & operator and keep it private
 *          2. Delete  * operator from class
 */

class BaseStopFromADDRMth1
{// 1. overload & operator and keep it private
    int _x;

public:
    BaseStopFromADDRMth1(void)          {;}
    BaseStopFromADDRMth1(int x): _x(x)  {;}
private:
    BaseStopFromADDRMth1* operator & (void)  
    {   std::cout << "BaseStopFromADDRMth1* operator & (void)" << std::endl;
        return this; }// Now by using & new instruction is called
};

class BaseStopFromADDRMth2
{// 2. Delete  * operator from class
    int _x;

public:
    BaseStopFromADDRMth2(void)          {;}
    BaseStopFromADDRMth2(int x): _x(x)  {;}

    BaseStopFromADDRMth2* operator & (void)  = delete;
};

void CallBaseStopFromADDRMth1(void);
void CallBaseStopFromADDRMth2(void); // 2,59
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Stop from from inheritance from my class
 * 
 *          1. Use final keyword, dont use any other tweak to achieve that
 *          2. Just use final keyword
 */
class BaseStopFromInheritance //final
{
private:
    int _x;
public:
    BaseStopFromInheritance(void)           {;}
    BaseStopFromInheritance(int x): _x(x)   {;}
};

class DerivedFromBaseInheritance: public BaseStopFromInheritance
{
private:
    int _y;
public:
    DerivedFromBaseInheritance(void) {;}
    DerivedFromBaseInheritance(int x, int y): BaseStopFromInheritance(x), _y(y) {;}
};

void CallStopFromInheritance(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How to write own atoi function
 * 
 *          Convert string to integer
 */
uint16_t MyAtoi(const char* str, uint8_t maxControl);

uint16_t ClasicAtoi(const char* str);
void CallAtoi(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   How vector work internaly
 */
void CallWorkingOfVestors(void);
//==========================================================================================================

#endif // _ADVANCE_PART_3_H