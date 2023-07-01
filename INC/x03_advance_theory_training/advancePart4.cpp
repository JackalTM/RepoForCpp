#include "advancePart4.h"

/***********************************************************************************************************
 * @brief   Is it posible to call constructor and deconstructor by your self?
 * 
 *          Dstructor sould not be called explictly. It is dengerous code
 *          If constructor is called widhout variable asign thn destructor is called in the same time   
 */
void CallBaseConstructorAndDeconstructor(void)
{
    // This work like that 
    BaseConstructorAndDeconstructor().~BaseConstructorAndDeconstructor();
}

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
void CallObjcectSlice(void)
{
    DerivedObjSlice myDerivedObjSlice;
    myDerivedObjSlice.dataD = 0x11;
    myDerivedObjSlice.dataB = 0xFF;
    std::cout << "myDerivedObjSlice.dataB = " << myDerivedObjSlice.dataB << std::endl;
    std::cout << "myDerivedObjSlice.dataD = " << myDerivedObjSlice.dataD << std::endl;


    BaseObjSlice myBaseObjSlice = myBaseObjSlice;
    std::cout << "myBaseObjSlice.dataB = " << myBaseObjSlice.dataB << std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is good way to count number of set bit using C++
 * 
 * 
 */
void CallCountNumberInCpp(void)
{
    int number, counter, i, tSize;

    tSize = sizeof(int) * 8;
    number = 0xFF;
    counter = 0x00;
    for(i=0; i<tSize; i++)
    {
        if((number & 0x01) == 0x01) counter++;

        number = (number >> 1);
    }
    std::cout << "Method1 Amount of set bits:= " << counter << std::endl;

    number = 0xFF;
    counter = 0x00;
    while(number)
    {
        counter = counter + (number & 0x01);
        number >>= 1;
    }
    std::cout << "Metho2 Amount of set bits:= " << counter << std::endl;

    number = 0xFF;
    counter = 0x00;
    for(counter=0; number; ++counter)
    {// Britan Kernightan way
        number = number & (number - 1);
    }
    std::cout << "Metho3 Amount of set bits:= " << counter << std::endl;
}// 3,32
//==========================================================================================================