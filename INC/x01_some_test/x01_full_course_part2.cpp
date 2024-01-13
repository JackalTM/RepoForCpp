#include "x01_full_course_part2.h"
#ifdef CMP_X01_FULL_COURSE_PART02_H

/*************************************************************************************
 * @name    ...
 * @brief   ...
 * 
 * @param   ...
 * @param   ...
 * 
 * @note    ...
 * 
 * @return  ...
*/
void CALL_StringTest01(void)
{
    std::string tStr = "abcdefgh";

    std::cout << "tStr = " << tStr << std::endl;
    std::cout << "tStr.lenght() = " << tStr.length() << std::endl;

    tStr.clear();
    std::cout << "tStr after tStr.clear() = " << tStr << std::endl;
    std::cout << "tStr.lenght() = " << tStr.length() << std::endl;
    std::cout << "tStr.empty() = " << tStr.empty() << std::endl;

    tStr.append("1234");
    tStr.append("abcd");
    std::cout << "tStr.append('1234'); tStr.append('abcd'); tStr= " << tStr << std::endl;

    tStr.insert(0, "A");
    tStr.insert(0, "CB");
    std::cout << "tStr.insert(0, 'A'); tStr.insert(0, 'CB'); tStr= " << tStr << std::endl;

    std::cout << "tStr.find('A')= " << tStr.find('A') << std::endl;

    std::cout << "Before tStr.erase(0, 2); tStr = " << tStr << std::endl;
    tStr.erase(0, 2);
    std::cout << "After  tStr.erase(0, 2); tStr = " << tStr << std::endl;
}
//====================================================================================

/*************************************************************************************
 * @name    ...
 * @brief   ...
 * 
 * @param   ...
 * @param   ...
 * 
 * @note    ...
 * 
 * @return  ...
*/
void CALL_(void)
{
    ;
}
//====================================================================================

#endif // CMP_X01_FULL_COURSE_PART02_H