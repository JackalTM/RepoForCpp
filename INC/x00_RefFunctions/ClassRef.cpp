#ifdef X00_CLASS_REF

#include "ClassRef.h"
#include <iostream>

ClassA::ClassA(LCD_interface_t& LCD_interface, uint8_t inID):
    refLcdInterface(LCD_interface)
{
    ID = inID;
}

ClassA::~ClassA(void)
{;}
void ClassA::ChangeValues(uint8_t inScrNum, uint8_t inParNum)
{
    refLcdInterface.scrNum = inScrNum;
    refLcdInterface.parNum = inParNum;
    return;
}
void ClassA::PrintValues(void)
{
    //std::cout << "ClassA Screen number     : " << int(refLcdInterface.scrNum) << std::endl;
    //std::cout << "ClassA Parameter number  : " << int(refLcdInterface.parNum) << "\n" << std::endl;
    printf("ClassA Screen number     : 0x%x \n", refLcdInterface.scrNum);
    printf("ClassA Parameter number  : 0x%x \n", refLcdInterface.parNum);
    printf("ClassA ID number         : 0x%x \n", ID);
}
//=============================================================================================================
ClassB::ClassB(LCD_interface_t& LCD_interface, uint8_t inID):
    refLcdInterface(LCD_interface),
    ID(inID)
{}
ClassB::~ClassB(void)
{;}
void ClassB::ChangeValues(uint8_t inScrNum, uint8_t inParNum)
{
    refLcdInterface.scrNum = inScrNum;
    refLcdInterface.parNum = inParNum;
    return;
}
void ClassB::PrintValues(void)
{
    //std::cout << "ClassB Screen number     : " << std::hex << refLcdInterface.scrNum << std::endl;
    //std::cout << "ClassB Parameter number  : " << std::hex << refLcdInterface.parNum << "\n" << std::endl;

    printf("ClassB Screen number     : 0x%x \n", refLcdInterface.scrNum);
    printf("ClassB Parameter number  : 0x%x \n", refLcdInterface.parNum);
    printf("ClassB ID number         : 0x%x \n", ID);
}
//=============================================================================================================
BaseClass01::BaseClass01(uint8_t inval1, uint8_t inval2)
{
    dat1 = inval1;
    dat2 = inval2;
    dat12 = (dat1 << 0) | (dat2 << 8);
}
BaseClass01::~BaseClass01(void)
{;}
void BaseClass01::PrintData(void)
{
    printf("dat1= %x dat2= %x dat12= %x \n", dat1, dat2, dat12);
}
//=============================================================================================================
GroupClass::GroupClass(uint8_t inval3, uint8_t inval4):
    BaseClass01(0x11, 0x22)
{
    dat3 = inval3;
    dat4 = inval4;
    dat34 = (dat3 << 0) | (dat4 << 8);
}
GroupClass::~GroupClass(void)
{;}
void GroupClass::PrintMyData(void)
{
    printf("dat3= %x dat4= %x dat34= %x \n", dat3, dat4, dat34);
}
//=============================================================================================================

#endif // #ifdef X00_CLASS_REF