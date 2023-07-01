#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <vector>

/***********************************************************************************************************
 * @brief   Is it posible to call constructor and deconstructor by your self?
 * 
 *          Dstructor sould not be called explictly. It is dengerous code
 *          If constructor is called widhout variable asign thn destructor is called in the same time   
 */
class BaseConstructorAndDeconstructor
{
private:
    int _x;
public:
    BaseConstructorAndDeconstructor(void)   {std::cout << "Class Constructor" << std::endl;}

    ~BaseConstructorAndDeconstructor(void)  {std::cout << "Class Deconstructor" << std::endl;}
};

void CallBaseConstructorAndDeconstructor(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   TO check optimazation code https://godbolt.org/
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief   How Cpp achieve function overloading
 *          Name mangling - changng name of functions and classes
 * 
 *          If function has namy forms for diffrnet king of input parameters.\
 *          Compiler create more function with diffrent name depend on parameter
 * 
 *          Function in class is just another function with name combination.
 */
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is object slicing in C++
 * 
 *          When assiging only BaseObjSlice data will be copied to BaseObjSlice instance
 */
class BaseObjSlice
{
private:
    int _x;
public:
    int dataB;
    BaseObjSlice(void)  { std::cout << "Base Class constructor   " << std::endl; }
    ~BaseObjSlice(void) { std::cout << "Base Class deconstructor " << std::endl; }
};

class DerivedObjSlice: public BaseObjSlice
{
private:
    int _x;
public:
    int dataD;
    DerivedObjSlice(void)  { std::cout << "Drived Class constructor    " << std::endl; }
    ~DerivedObjSlice(void) { std::cout << "Derived Class deconstructor " << std::endl; }
};

void CallObjcectSlice(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is good way to count number of set bit using C++
 * 
 */
void CallCountNumberInCpp(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is override keyowrd in C++
 * 
 *          Testing beomes more easy with iths
 *          Compile time check can be performed. Future error can be reduced
 * 
 *          void Function(void) override { std::cout << "Derived Class function " << std::endl; } points to
 *          virtual void Function(void) { std::cout << "Base Class function " << std::endl; } and override tells explicid 
 *          that this method need to be overrided
 */
class BaseOverrideKey
{
    int _x;
public:
    virtual void Function(void) { std::cout << "Base Class function " << std::endl; }
};

class DerivedOverrideKey: public BaseOverrideKey
{
    int _y;
public:
    //void Function(void) { std::cout << "Derived Class function " << std::endl; }
    void Function(void) override { std::cout << "Derived Class function " << std::endl; }
    //void Function(int x) override { std::cout << "Derived Class function " << std::endl; }
};

void CallOverrideKey(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is placement new in C++
 * 
 *          In case when more object need to be alocated dynamic it is better to upront alocated moemory
 *          For Kernel its is 
 */
class BasePlecementNew
{
    int _offsetMem;
public:
    BasePlecementNew(int offsetMem)  
    {   std::cout << "Base Class Constructor    ADDR + 0x" << std::hex << offsetMem << std::endl; 
        _offsetMem = offsetMem;}

    ~BasePlecementNew(void) 
    {    std::cout << "Base Class Deconstructor  ADDR + 0x" << std::hex << _offsetMem << std::endl; }
};
void CallPlacementNew(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Reinterpreted cast
 *          
 *          It can perform dangerous conversation beacuse it can typecast ant pointer to ant other pointer
 */
class Golock
{
private:
    int _n;
public:
    void Swing(int n)   
    {   std::cout << "Golock swings " << n << " times" <<  std::endl; 
        _n = n; }
};

class Paranga
{
private:
    int _n;
public:
    void Swing(int n)   
    {   std::cout << "Paranga swings " << n << " times" <<  std::endl; 
        _n = n; }
};

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
    uint32_t volume;
}someTool_t;

void CallReinterpretedCast1(void);
void CallReinterpretedCast2(void);
//==========================================================================================================

/***********************************************************************************************************
 * @brief   
 * 
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief   
 * 
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief   
 * 
 */

//==========================================================================================================

/***********************************************************************************************************
 * @brief   
 * 
 */

//==========================================================================================================