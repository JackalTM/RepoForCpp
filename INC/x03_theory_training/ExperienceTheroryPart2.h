#include <stdio.h>
#include <iostream>

/**************************************************************************************
 * @brief   Dynamic cast
 * @note    
 * @return
*/
class BaseClass
{
private:
    /* data */
public:
    virtual void Print(void);
};

class Derived11: public BaseClass 
{
private:
    /* data */
public:
    void Print(void);
};
class Derived22: public BaseClass 
{
private:
    /* data */
public:
    void Print(void);
};

void CallDynamicCast(void);

