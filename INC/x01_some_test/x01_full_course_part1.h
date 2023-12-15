#include "_x01_some_test.h"
#ifdef CMP_X01_FULL_COURSE_PART01_H

#include <iostream>
#include <vector>

/***************************************************************************
 * Printing in C++
*/
void CALL_SomedataPrint(void);
void CALL_NamespaceTest(void);
//==========================================================================

/***************************************************************************
 * Urzywanie "typedef" oraz "using" naprzemienie
 * typedef: Reserved keywork used to create an additional name alias 
 *          for another data dype.
 *          Helps with readability and reduce typos.
 *          Use when thers is clear benefit. Can be replaced with using (better is templates)
*/
typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string text_t;
using std_vec_pair_t = std::vector<std::pair<std::string, int>>;
using std_str_t = std::string;
void CALL_typedef_keyword(void);
//==========================================================================

/***************************************************************************
 * tenary operator
*/
void CALL_teneryoperator(void);
//==========================================================================
#endif // CMP_X01_FULL_COURSE_PART01_H