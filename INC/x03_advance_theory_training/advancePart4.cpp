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
    myDerivedObjSlice.dataD = 1;
    myDerivedObjSlice.dataB = 2;
    std::cout << "myDerivedObjSlice.dataB = " << myDerivedObjSlice.dataB << std::endl;
    std::cout << "myDerivedObjSlice.dataD = " << myDerivedObjSlice.dataD << std::endl;


    BaseObjSlice myBaseObjSlice = myDerivedObjSlice;
    std::cout << "myBaseObjSlice.dataB = " << myBaseObjSlice.dataB << std::endl;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is good way to count number of set bit using C++
 * 
 */
void CallCountNumberInCpp(void)
{
    int number, counter, i, tSize;

    tSize = sizeof(int) * 8;
    number = 0x7F;
    counter = 0x00;
    for(i=0; i<tSize; i++)
    {
        if((number & 0x01) == 0x01) counter++;

        number = (number >> 1);
    }
    std::cout << "Method1 Amount of set bits:= " << counter << std::endl;

    number = 0x7F;
    counter = 0x00;
    while(number)
    {
        counter = counter + (number & 0x01);
        number >>= 1;
    }
    std::cout << "Metho2 Amount of set bits:= " << counter << std::endl;

    number = 0x7F;
    counter = 0x00;
    for(counter=0; number; ++counter)
    {// Britan Kernightan way
        number = number & (number - 1);
    }
    std::cout << "Metho3 Amount of set bits:= " << counter << std::endl;
}// 3,32
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
void CallOverrideKey(void)
{
    BaseOverrideKey* pBaseOverrideKey = new DerivedOverrideKey();

    pBaseOverrideKey->Function();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is placement new in C++
 * 
 *          In case when more object need to be alocated dynamic it is better to upront alocated moemory
 *          For Kernel its is 
 */
void CallPlacementNew(void)
{
    // Normal case:
    std::cout << "Normal case:" << std::endl;
    BasePlecementNew* pBasePlecementNew = new BasePlecementNew(0x00);
    delete pBasePlecementNew;

    // Placement new case
    std::cout << "Placement new case:" << std::endl;

    uint8_t* pBase = new uint8_t[10 * sizeof(BasePlecementNew)]; // Memory pool

    BasePlecementNew* pBasePlecementNew1 = new (pBase + 0) BasePlecementNew(0x00);
    BasePlecementNew* pBasePlecementNew2 = new (pBase + 4) BasePlecementNew(0x04);
    BasePlecementNew* pBasePlecementNew3 = new (pBase + 8) BasePlecementNew(0x08);

    // Only reason to explicid call destructor in placement new
    pBasePlecementNew1->~BasePlecementNew();
    pBasePlecementNew2->~BasePlecementNew();
    pBasePlecementNew3->~BasePlecementNew();

    delete[] pBase;

    // Drestruction neef to be done bacwards
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Reinterpreted cast
 *          
 *          It can perform dangerous conversation beacuse it can typecast ant pointer to ant other pointer
 */
void CallReinterpretedCast1(void)
{
    Golock* pGolock = new Golock();
    Paranga* pParanga = new Paranga();

    Golock* newGolock = reinterpret_cast<Golock*>(pParanga);

    newGolock->Swing(9);

    pGolock->Swing(2);
    pParanga->Swing(1);
}
void CallReinterpretedCast2(void)
{
    someTool_t tTool;

    tTool.x = 0x1100;
    tTool.y = 0x3322;
    tTool.z = 0x5544;
    tTool.volume = 0x99887766;

    uint8_t* pTool = reinterpret_cast<uint8_t*>(&tTool);

    std::cout << "tTool.x = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 0)) <<   std::endl;
    std::cout << "tTool.y = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 2)) <<   std::endl;
    std::cout << "tTool.z = " << std::hex << *(reinterpret_cast<uint16_t*>(pTool + 4)) <<   std::endl;
    std::cout << "tTool.volume = " << std::hex << *(reinterpret_cast<uint32_t*>(pTool + 8)) <<   std::endl;

    std::cout << "tTool.x = " << std::hex << tTool.x <<   std::endl;
    std::cout << "tTool.y = " << std::hex << tTool.y <<   std::endl;
    std::cout << "tTool.z = " << std::hex << tTool.z <<   std::endl;
    std::cout << "tTool.volume = " << std::hex << tTool.volume <<   std::endl;
}
//==========================================================================================================