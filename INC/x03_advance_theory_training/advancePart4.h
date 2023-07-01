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
 * 
 */
void CallCountNumberInCpp(void);