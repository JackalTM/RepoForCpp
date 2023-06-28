#include <stdint.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct 
{
    uint8_t scrNum;
    uint8_t parNum;
}LCD_interface_t;

class ClassA
{
private:
    LCD_interface_t& refLcdInterface;
    uint8_t ID;
public:
    ClassA(LCD_interface_t& LCD_interface, uint8_t inID);
    ~ClassA(void);

    void ChangeValues(uint8_t inScrNum, uint8_t inParNum);
    void PrintValues(void);
};
//===========================================================
class ClassB
{
private:
    LCD_interface_t& refLcdInterface;
    uint8_t ID;
public:
    ClassB(LCD_interface_t& LCD_interface, uint8_t inID);
    ~ClassB(void);

    void ChangeValues(uint8_t inScrNum, uint8_t inParNum);
    void PrintValues(void);
};
//===========================================================
class BaseClass01
{
private:
    uint8_t dat1;
    uint8_t dat2;
public:
    uint16_t dat12;
    BaseClass01(uint8_t inval1, uint8_t inval2);
    ~BaseClass01(void);

    void PrintData(void);
};
//===========================================================
class GroupClass:public BaseClass01
{
private:
    uint8_t dat3;
    uint8_t dat4;
public:
    uint16_t dat34;
    GroupClass(uint8_t inval3, uint8_t inval4);
    ~GroupClass(void);

    void PrintMyData(void);
};