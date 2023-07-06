#include "advancePart5.h"
#ifdef _ADVANCE_PART_5_H

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

    errorType_t ERRORS_ENUM;
    ERRORS_ENUM = ERROR_WRONG_DATA;
    switch (ERRORS_ENUM)
    {
    case ERROR_WRONG_DATA: std::cout << "normalEnum Wrong data  " <<  ERRORS_ENUM <<   std::endl;   break;
    case ERROR_SHORT_DATA: std::cout << "normalEnum Short data  " <<  ERRORS_ENUM <<   std::endl;   break;
    case ERROR_LONG_DATA:  std::cout << "normalEnum Long data   "  <<  ERRORS_ENUM <<   std::endl;   break;
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

/***********************************************************************************************************
 * @brief  Returnng multiple values in C++ 
 *          Using tuplets from std
 */
std::tuple<uint32_t, uint32_t, uint64_t, std::string> RetTupleFunction(uint8_t inIndex)
{
    uint32_t id = inIndex;
    uint32_t price = inIndex;
    uint64_t code = 1- inIndex ;

    return std::make_tuple(id, price, code, "OK");
}
void CallRetTupleFunction(void)
{
    uint32_t id;
    uint32_t price;
    uint64_t code;
    std::string someStr;

    std::tie(id, price, code, someStr) = RetTupleFunction(0x02);
    std::cout << " id:=" <<  id << " price:=" <<  price << " code:=" <<  code << " someStr:= " << someStr <<  std::endl; 

    dataFrameRow_t tRow = RetTupleFunction(0x03);
    id          = std::get<0>(tRow);
    price       = std::get<1>(tRow);
    code        = std::get<2>(tRow);
    someStr     = std::get<3>(tRow);
    std::cout << " id:=" <<  id << " price:=" <<  price << " code:=" <<  code << " someStr:= " << someStr <<  std::endl;
}// 4,51
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why we need virtual destructor
 * 
 */
void CallVirtualDestructor(void)
{
    BaseVirtualDestructor* pBaseFromBase = new BaseVirtualDestructor();

    DerivedVirtualDestructor* pBaseFromDerived = new DerivedVirtualDestructor();

    pBaseFromBase->Print();
    pBaseFromDerived->Print();

    std::cout << "sizeof(pBaseFromBase) =  "<<              sizeof(BaseVirtualDestructor) <<        std::endl;
    std::cout << "sizeof(DerivedVirtualDestructor) =  "<<   sizeof(DerivedVirtualDestructor) <<     std::endl;

    delete pBaseFromBase;
    delete pBaseFromDerived;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the places where initializer list must be present
 */
void CallListInitializer(void)
{
    int someInt = 0;
    BaseListInitializer myBase11(0x11, someInt);
    BaseListInitializer myBase22(0x22, someInt);

    myBase11.Print();
    myBase22.Print();

    DerivedListInitializer myDerivedListInitializer(0x11, 0x22, someInt);
    myDerivedListInitializer.Print();
    //myDerivedListInitializer::BaseListInitializer.Print();

    std::cout << "someInt = " << someInt << std::endl; 

}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the drawback of vectors in C++
 *          It overalocated memory which some times could be very bad in terms of performance
 *          When ever capacity of vecors it copy element from previous to new vector 
 */
void CallDrawbackOfVectors(void)
{
    int i = 0x00;
    std::vector<int> myVector;

    std::cout << "SIZE:     " << myVector.size() << std::endl; 
    std::cout << "CAPACITY: " << myVector.capacity() << std::endl; 

    myVector.push_back(i++);
    myVector.push_back(i++); // New momory alocated x2
    myVector.push_back(i++);
    myVector.push_back(i++); 

    myVector.push_back(i++); // New momory alocated x2

    std::cout << "SIZE:     " << myVector.size() << std::endl; 
    std::cout << "CAPACITY: " << myVector.capacity() << std::endl; 
}
//==========================================================================================================

#endif // _ADVANCE_PART_5_H