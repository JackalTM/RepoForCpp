/*
 * LCD_application.h
 *
 * Created: 17.05.2024 
 *  Author: Wiki
 */
#include "converion_methods.h"
#ifdef CMP_INC_CONVERSION_METHODS

/*****************************************************************************************************
 * @name		  void
 * @brief		  void
 * @param[in]	void
 * @note		  void
 * @return		void
 */
//====================================================================================================

/*****************************************************************************************************
 * @name		  itoa_simple_helper
 * @brief		  void
 * @param[in]	dest Pointer to destination array with strig data 
 * @note		  void
 * @return		void
 */
char* NumbersConversion::itoa_simple_helper(char *dest, int i) 
{
  if (i <= -10) 
  {
    dest = itoa_simple_helper(dest, i/10);
  }
  
  *dest++ = '0' - i%10;
  return dest;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		  itoa_simple
 * @brief		  void
 * @param[in]	dest Pointer to destination array with strig data 
 * @note		  void
 * @return		void
 */
char* NumbersConversion::itoa_simple(char *dest, int i) 
{
  char *s = dest;
  if (i < 0) 
  {
    *s++ = '-';
  } 
  else 
  {
    i = -i;
  }
  *itoa_simple_helper(s, i) = '\0';
  return dest;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		  Uint_to_str_dec
 * @brief		  void
 * @param[in]	dest Pointer to destination array with strig data 
 * @note		  void
 * @return		void
 */
 char* NumbersConversion::Uint_to_str_dec(char *pStr, uint8_t uint)
{
  _Str_n++;
  if(_Str_n < _StrMax)
  {
    if (uint >= 10) 
    {
      pStr = Uint_to_str_dec(pStr, uint/10);
    }
    
    *pStr++ = '0' + (uint%10);
    return pStr;
  }
  else
  {
    return pStr;
  }
}
//====================================================================================================

/*****************************************************************************************************
 * @name		  Uint_to_str_hex
 * @brief		  void
 * @param[in]	dest Pointer to destination array with strig data 
 * @note		  void
 * @return		void
 */
 char* NumbersConversion::Uint_to_str_hex(char *pStr, uint8_t uint)
{
  _Str_n++;
  if(_Str_n < _StrMax)
  {
    if (uint >= 0x10) 
    {
      pStr = Uint_to_str_hex(pStr, uint/0x10);
    }
    
    uint8_t temp;
    temp = (uint%0x10);

    if(temp <= 0x9)
    { *pStr++ = '0' + temp;}
    else //(temp >= 0xA)
    { *pStr++ = 'A' + temp;}
    
    return pStr;
  }
  else
  {
    return pStr;
  }
}
//====================================================================================================

/*****************************************************************************************************
 * @name		ConvertTime
 * @brief		Deconstructor
 */
ConvertTime::ConvertTime(void)
{
  _hour[0] = 0;   _hour[1] = 0;
  _min[0] = 0;    _min[1] = 0;
  _sec[0] = 0;    _sec[1] = 0;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		~ConvertTime
 * @brief		Deconstructor
 */
ConvertTime::~ConvertTime(){;}
//====================================================================================================

/*****************************************************************************************************
 * @name		  GetTimeString
 * @brief		  Asign whole string 
 * @param[in]	pChar Pointer to char array 
 * @note		  void
 * @return		void
 */
void ConvertTime::GetTimeString(char pChar[])
{
    pChar[0] = _hour[0];    
    pChar[1] = _hour[1];
    pChar[2] = ':';
    pChar[3] = _min[0];    
    pChar[4] = _min[1];
    pChar[5] = ':';
    pChar[6] = _sec[0];     
    pChar[7] = _sec[1];
}
//====================================================================================================

/*****************************************************************************************************
 * @name		  IncBySec
 * @brief		  Increase time by one second
 * @param[in]	void
 * @note		  void
 * @return		void
 */
void ConvertTime::IncBySecAmount(uint16_t nSec)
{
  ;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		ConvertNumberTostring
 * @brief		This method convert number to string in format HEX
 * 
 * @param[in] number Number that will be converted to string
 * @param[in]	arrChar[] Pointer to array of chars
 * @param[in] lenght Lenght of a destinatin string
 * 
 * @note		void
 * @return	void
 */

void ConvertTime::NumToString(uint8_t number, char arrChar[], DecimalNumberStringSize strSize)
{
  NumbersConversion::SetMaxStringLenght(strSize);

  *(NumbersConversion::Uint_to_str_dec(arrChar, number))  = '\0';
}
void ConvertTime::NumToString(uint8_t number, char arrChar[], HexadeciNumberStringSize strSize)
{
  NumbersConversion::SetMaxStringLenght(strSize);

  *(NumbersConversion::Uint_to_str_hex(arrChar, number))  = '\0';
}
//====================================================================================================

//====================================================================================================
#endif // _INC_CONVERSION_METHODS
//====================================================================================================

void TestConversionMethod(uint8_t number)
{
  char arrChars[64];
  uint8_t i;

  ConvertTime myConv;
  myConv.NumToString(number, arrChars, TYPE_DEC_uin8_t);

  putchar('\n');

  printf("=======START==== \n");
  for(i=0; i<64; i++)
  {
    if(arrChars[i] == '\0') break;

    putchar((i + '0')); putchar('\t'); 

    putchar(arrChars[i]); 

    putchar('\n');
  }
  putchar('\n');
  printf("=======END====== \n");  
}