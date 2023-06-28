#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <algorithm>

void CALL_BasicTest(void);

/**************************************************************************************
 * @brief   Test of a friendship in C++ 
 * @note    Friend function can access private data
 * @return
*/
class BaseClassFriend
{
private:
    unsigned int x;

public:
    BaseClassFriend(unsigned int x);
    ~BaseClassFriend();

    friend void FriendFunction(BaseClassFriend& RefBase, unsigned int x);
};
void FriendFunction(BaseClassFriend& RefBase, unsigned int x);

void CallFriendFunction(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Test of auto keyword
 * @note    
 * @return
*/
void AutoKeyword(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Code bloat is the production of code that is percieved as unnecessary long, 
 *          slow or otherwise wastefullof recources
*/
void CodeBloatExample(void);

/**************************************************************************************
 * @brief   Inline function test
*/
class InineTest
{
private:
    int _x;
public:
    inline void print(void);
};
void CallInlineTest(void);

/**************************************************************************************
 * @brief   Constant cast in C++
 *          The xpresion of const_cast<t>(v) can be used to change const or volatile 
 *          qualifiers of pointers or reference
 *          Where T must to be a pointer
*/
void CallConstantCast(void);
//=====================================================================================

/**************************************************************************************
 * @brief   What is one of the use of decltype in C++
 *          It checks the type of expresion
*/
void CallDecltype(void);
//=====================================================================================

/**************************************************************************************
 * @brief   pointers and references
 *          Pointer is a memory adres of a variable
 *          Reference is a anaother alias for this variable and have to be asigned diring creation
*/
void CallTestPointersAndRef(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Differences b/w ranges based for loop and for_each in C++
 *          Some of the diff are shown below
*/
void print(int values);
void CallVecorRanges(void);
//=====================================================================================

/**************************************************************************************
 * @brief   Virtual methods in class
*/
class BaseClass
{
public:
    void A_print(void);
    virtual void B_print(void);
    virtual void C_print(void);
    //virtual void PurecVirtual(void) = 0x00;
};
class NextClass : public BaseClass
{
public:
    void A_print(void);
    void B_print(void);
    virtual void C_print(void);
};

class Weapon
{
public:
    virtual void Usage(int n) = 0;
};
class Sword : public Weapon
{
public:
    void Usage(int n);
};
class Rifle: public Weapon
{
public:
    void Usage(int n);
};

void CallVirtualFunctionsTest1(void);
void CallVirtualFunctionsTest2(void);
void CallPureVirtualFunctions(void);
//=====================================================================================


