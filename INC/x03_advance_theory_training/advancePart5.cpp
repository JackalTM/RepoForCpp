#include "advancePart5.h"
#ifdef CMP_ADVANCE_PART_5_H

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
    case ERROR_LONG_DATA:  std::cout << "normalEnum Long data   " <<  ERRORS_ENUM <<   std::endl;   break;
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
    BaseVirtualDestructor* pBaseFromBase = new BaseVirtualDestructor('B');

    DerivedVirtualDestructor* pBaseFromDerived = new DerivedVirtualDestructor('D');

    pBaseFromBase->Print();
    pBaseFromDerived->Print();

    std::cout << "========================================" << std::endl;
    std::cout << "sizeof(pBaseFromBase) =  "<<              sizeof(BaseVirtualDestructor) <<        std::endl;
    std::cout << "sizeof(DerivedVirtualDestructor) =  "<<   sizeof(DerivedVirtualDestructor) <<     std::endl;
    std::cout << "========================================" << std::endl;

    delete pBaseFromBase;
    delete pBaseFromDerived;
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What are the places where initializer list must be present
 * 
 *          When constatnt is initialized
 *          When reference is initialized
 *          When class is asigning inside class
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

    std::cout << "from Base clss | _X = " << myDerivedListInitializer.GetValue() << std::endl; 

    int y,x;
    std::tie( y, x) = myDerivedListInitializer.GetBothValues();
    std::cout << "Both values as tuple _Y=" << y << " _X=" <<  x << std::endl;
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

/***********************************************************************************************************
 * @brief   What is Constructor Delegation in C++
 */
void CallDelegationCOnstruction(void)
{
    BaseConstrDelegation myBaseConstrDelegation11;
    BaseConstrDelegation myBaseConstrDelegation22(2);
    BaseConstrDelegation myBaseConstrDelegation33(2, 2);

    myBaseConstrDelegation11.Print();
    myBaseConstrDelegation22.Print();
    myBaseConstrDelegation33.Print();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What does the printf and scanf function returns?
 * 
 *          printf returns number of characters printed succesfuly 
 *          scanf returns the number of elements read successfully from console
 */
void CallTestPrintfScanf(void)
{
    char pArray[32];
    int someval = -1;
     
    uint16_t printfOut = printf("Value of someval %x \n", someval);
    uint16_t scanfOut  = scanf("%s", pArray);

    printf("printfOut= %x \n", printfOut);
    printf("scanfOut=  %x \n", scanfOut);

    getchar();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is RVO and NRVO in C++?
 * 
 *          It stands for return value optimazition and named return value optimazition
 * 
 *          -fno-elide-constructor allow unesesary call of constructor
 */
Base_RVO_NRVO FunctionOf_RVO_NRVO(void)
{
    return Base_RVO_NRVO();
}

void Call_RVO_NRVO(void)
{
    Base_RVO_NRVO myBase_RVO_NRVO = FunctionOf_RVO_NRVO();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the best place to use enum in C++
 *          
 *          Enum is used in some limited sets of values
 *          Function can take one values from set like parameter input
 */
void CallEnumTestFunc(void)
{
    MAIN_COLORS myMAIN_COLORS = MAIN_COLORS::BLU;

    switch (myMAIN_COLORS)
    {
    case MAIN_COLORS::RED: 
        std::cout << "red" << std::endl;   break;

    case MAIN_COLORS::GRN: 
        std::cout << "green" << std::endl;   break;

    case MAIN_COLORS::BLU: 
        std::cout << "blue" << std::endl;   break;
    
    default:
        break;
    }
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the diffrence between struct and class in C++
 *  
 *          Class memebers are private by dafault
 *          Struct memebers are public by default
 * 
 *          If class is derivef widhout specifer then it will be private
 *          If struct is derived widhout specifer then it will be public
 */
void Call_classTestType_structTestType(void)
{
    structDerivedType myStructDerivedType;

    myStructDerivedType.x = 0;
    myStructDerivedType.y = 0;
    myStructDerivedType.z = 0;

    myStructDerivedType.a = 0;
    myStructDerivedType.b = 0;
    myStructDerivedType.c = 0;

    classDrivedType myClassDrivedType;
/*
    myClassDrivedType.x = 0;
    myClassDrivedType.y = 0;
    myClassDrivedType.z = 0;

    myClassDrivedType.a = 0;
    myClassDrivedType.b = 0;
    myClassDrivedType.c = 0;
*/
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the order of functionevaluation in C++
 */
bool FunParamOrder_build(void)
{   std::cout << "Some data is build!!" << std::endl;
    return false; }

bool FunParamOrder_use(void)
{   std::cout << "Builded data are used!!" << std::endl;
    return false; }

void FunParamOrder_power2(unsigned int inA)
{
    std::cout << "pwr() = " << inA * inA << std::endl;
}
void FunParamOrder_mull(unsigned int inA, unsigned int inB)
{
    std::cout << "mull() = " << inA * inB << std::endl;
}

void CallFunParamOrder(void)
{
    FunParamOrder_power2(FunParamOrder_build() + FunParamOrder_use());
    std::cout << "==================================================" << std::endl;
    FunParamOrder_mull(FunParamOrder_build(), FunParamOrder_use());
    std::cout << "==================================================" << std::endl;
    uint8_t tBool = FunParamOrder_build() & FunParamOrder_use();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   What is the diferences in references and pointers in C++
 *          And when is best usage of both of them
 * 
 *          Reference: Used in function paremeter and return type
 *          1. Pass big object
 *          2. Avoid object slice
 *          3. Modify local variables of call function
 * 
 *          Pointers: Algoritms and data structures like list , tree graph
 *          1. On the end of node NULL pointer can be used
 *          2. Pointer can be changes to another pointer
 *          3. 
 */ 
void SomeFun(Weapon& inClass)
{
    inClass.Print();
}

void CallPtrAndRefDifference1(void)
{
    Weapon  myWeapon;
    Blade   myBlade;    

    SomeFun(myWeapon);
    SomeFun(myBlade);
}

void CallPtrAndRefDifference2(void)
{// Copy constructor with using reference and pointer
    OpticREF myOpticREF('A', 7);
    myOpticREF.Print();

    OpticREF myOptREFcopy = myOpticREF;
    myOptREFcopy.Print();

std::cout << "==================================================" << std::endl;

    OpticPTR myOpticPTR('A', 7);
    myOpticPTR.Print();

    OpticPTR myOptPTRcopy = (OpticPTR*)&myOpticPTR;
    myOptPTRcopy.Print();
}
//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why static define data memeber must to be defined in file.cpp and not in file.h
 * 
 *          If it is called in file.h then it is intialized multiple times.
 *          Compiler then will throw error multiple definitions
 */

sword_t katana;
sword_t twoAndHalfHand;

void Callstaticmemebers(void)
{
    katana.mass = 2;
    katana.lenght = 120;
    katana.tickness = 5;
    katana.type = 0x22;
}

//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why is better to pass by Reference or by Pointer then by value.
 * 
 *          
 */

void PrintVestorValues(std::vector<uint64_t> &refVector)
{
    uint64_t tEle;
    uint8_t i, i_max;
    std::cout  << "Vector values: " << tEle << std::endl;

    i_max = refVector.size();
    for(i=0; i_max;  i++)
    {
        tEle = refVector[i];
        std::cout  << "- " << tEle << std::endl;
    }
}

void CallRefAndPointerDeffrerence(void)
{
    std::vector<uint64_t> tVector;

    tVector.push_back(1);
    tVector.push_back(2);
    tVector.push_back(3);

    uint8_t i, i_max;
    i_max = tVector.size();
    for(i=0; i_max;  ++i)
    {
        std::cout  << "- " << tVector[i] << std::endl;
    }

    //PrintVestorValues(tVector);
}

//==========================================================================================================

/***********************************************************************************************************
 * @brief   Why size of an empty class or structure is not zero in C++?
 * 
 *          Returning ref to local variable can be coz its can cause segmentacion error
 *          
 *          This is cause cpp cause to seperate each other.
 *          But when class or struct has some values inside then size would by of that size.
 */

void CallTestEmptyClassAndStruct(void)
{
    uint16_t tClassSize     = sizeof(SomeTestEmptyClass);
    uint16_t tStructSize    = sizeof(sometestEmptyStruct_t); 

    std::cout  << "Both Class and strut have no data inside: "  << std::endl;
    std::cout  << "Empty Class - sizeof(SomeTestEmptyClass)     = " << tClassSize << " B" << std::endl;
    std::cout  << "Empty Class - sizeof(sometestEmptyStruct_t)  = " << tStructSize << " B" << std::endl;

    tClassSize  = sizeof(SomeTestClass);
    tStructSize = sizeof(sometestStruct_t);
    std::cout  << "Both Class and strut have uint16_t variable inside: "  << std::endl;
    std::cout  << "Empty Class - sizeof(SomeTestClass)          = " << tClassSize << " B" << std::endl;
    std::cout  << "Empty Class - sizeof(sometestStruct_t)       = " << tStructSize << " B" << std::endl;
}
//==========================================================================================================




#endif // CMP_ADVANCE_PART_5_H