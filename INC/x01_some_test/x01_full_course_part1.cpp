#include "x01_full_course_part1.h"
#ifdef _X01_FULL_COURSE_PART01

//**********************************************************************************************************
// wyświetlaie w C++
/************************************************************************************
 * @name    CALL_SomedataPrint
 * @brief   CCall print std::
 * @param   void
 * @return  void
*/
void CALL_SomedataPrint(void)
{
    std::cout << "X01_FULL_COURSE_PART01" << std::endl;
    std::cout << "CALL_SomedataPrint()" << std::endl;
}
//====================================================================================

//**********************************************************************************************************
// Test namespace "first"
namespace first 
{
    int x = 0x10;
}

// Test namespace "second"
namespace second
{
    int x = 0x20;
}
/************************************************************************************
 * @name    CALL_SomedataPrint
 * @brief   When using namespace scope 
 *          Example first::x its x in namespace x
 * @param   void
 * 
 * @note    Solution for same name conflist
 * 
 * @return  void
*/
void CALL_NamespaceTest(void)
{
    int x = 0x00;
    std::cout << "CALL_NamespaceTest()" << std::endl;
    std::cout << "        x = " << x << std::endl;
    std::cout << " first::x = " << first::x << std::endl;
    std::cout << "second::x = " << second::x << std::endl;
}
//====================================================================================

/************************************************************************************
 * @name    CALL_typedef_keyword
 * @brief   Usig tyedef changes name for some types of a variable or a class or structure
 * @param   void
 * 
 * @note    using is more popular than typedef
 * 
 * @return  void
*/
void CALL_typedef_keyword(void)
{
    std::vector<std::pair<std::string, int>> pairlistFull;
    pairlist_t pairListShort;

    text_t someStr = "some str";
    // 37,16
}
//====================================================================================

/************************************************************************************
 * @name    CALL_teneryoperator
 * @brief   Replacement for using if/else statment
 * @param   void
 * 
 * @note    using is more popular than typedef
 * 
 * @return  void
*/
void CALL_teneryoperator(void)
{
    char i, j;
    int x, y;
    x   = 0;
    y   = 0;

    for(i=0; i< 0xf0; i++)
    {
        j = i%2;
        j == 0x00 ? x++ : y++;
    }

    std::cout << "Even num:= " << x << "Odd number:= " << y << std::endl;
}
//====================================================================================

#endif // _X01_FULL_COURSE_PART01