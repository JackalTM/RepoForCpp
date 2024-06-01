/*
 * LCD_application.h
 *
 * Created: 17.05.2024 
 *  Author: Wiki
 */
#include "_x01_some_test.h"
#ifdef CMP_INC_CONVERSION_METHODS

#include "stdint.h"
#include "string"

#define CONVERSION_TYPE_DEC_uint8_t 4U
#define CONVERSION_TYPE_DEC_uint16_t 6U
#define CONVERSION_TYPE_DEC_uint32_t 10U

#define CONVERSION_TYPE_DEC_int8_t 5U
#define CONVERSION_TYPE_DEC_int16_t 7U
#define CONVERSION_TYPE_DEC_int32_t 11U

enum DecimalNumberStringSize
{
    TYPE_DEC_uin8_t = 4U, TYPE_DEC_int8_t = 5U, 
    TYPE_DEC_uint16_t = 6U, TYPE_DEC_int16_t = 7U,
    TYPE_DEC_uint32_t = 10U, TYPE_DEC_int32_t = 11U,
};
enum HexadeciNumberStringSize
{
    TYPE_HEX_uin8_t = 3U, TYPE_HEX_int8_t = 3U, 
    TYPE_HEX_uint16_t = 5U, TYPE_HEX_int16_t = 5U,
    TYPE_HEX_uint32_t = 8U, TYPE_HEX_int32_t = 8U
};

struct NumberStrSize_t
{
    enum enum_DecimalNumberStringSize
    {
        TYPE_DEC_uin8_t = 4U, TYPE_DEC_int8_t = 5U, 
        TYPE_DEC_uint16_t = 6U, TYPE_DEC_int16_t = 7U,
        TYPE_DEC_uint32_t = 10U, TYPE_DEC_int32_t = 11U,
    };
}; // https://en.cppreference.com/w/cpp/language/enum

/*****************************************************************************************************
 * @name		NumbersConversion
 * @brief		Clas to convert nmbers system
 */
class NumbersConversion
{
private:
    uint8_t _StrMax, _Str_n;

    char* itoa_simple_helper(char *dest, int i);
    char* itoa_simple(char *dest, int i);

public:
    NumbersConversion(void) {;}
    ~NumbersConversion() {;}

    void SetMaxStringLenght(DecimalNumberStringSize strSize)     { _StrMax = strSize; _Str_n = 0; }
    void SetMaxStringLenght(HexadeciNumberStringSize strSize)    { _StrMax = strSize; _Str_n = 0; }
    
    char* Uint_to_str_dec(char *pStr, uint8_t uint);
    char* Uint_to_str_hex(char *pStr, uint8_t uint);
};
//====================================================================================================

/*****************************************************************************************************
 * @brief   Definitions for time conversion
 */
#define TIME_CONVERSION_STR_LEN 0x08U

#define TIME_CONVERSION_HOURS_MAX 24U
#define TIME_CONVERSION_MINUTES_MAX 60U
#define TIME_CONVERSION_SOCUNDS_MAX 60U
//====================================================================================================

/*****************************************************************************************************
 * @name		ConvertTime
 * @brief		Clas to convert nmbers system
 */
class ConvertTime: private NumbersConversion
{
private:
    // HH-MM-SS
    uint8_t hours, minutes, seconds, _index;
    char _hour[2];
    char _min[2];
    char _sec[2];

public:
    ConvertTime(void);
    ~ConvertTime();

    void GetTimeString(char pChar[]);
    void IncBySecAmount(uint16_t nSec);

    void NumToString(uint8_t number, char arrChar[], DecimalNumberStringSize strSize);
    void NumToString(uint8_t number, char arrChar[], HexadeciNumberStringSize strSize);
};
//====================================================================================================
#endif // _INC_CONVERSION_METHODS
//====================================================================================================

void TestConversionMethod(uint8_t number);