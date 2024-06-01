/*
 * LCD.h
 *
 * Created: 24.11.2020 12:41:12
 *  Author: Wiki
 */ 
#include "_x01_some_test.h"
#ifdef CMP_X01_LCD_DATA_CONTROL_H
/****************************************************************************************************************
 * Defintions if include required 
*/
#ifndef LCD_DATA_CONTROL_H_
#define LCD_DATA_CONTROL_H_

#include "stdint.h"
#include "stdio.h"
#define TRUE 0xFFU
#define FALSE 0x00U
//===============================================================================================================

/****************************************************************************************************************
 * Display size parameters
*/
#define DISPLAY_BUFFER_MAX_ROW_AMOUT 16U
#define DISPLAY_BUFFER_MAX_COL_AMOUT 2U

#define DISPLAY_BUFFER_CURRSOR_IDX_START 0U
#define DISPLAY_BUFFER_CURRSOR_IDX_END 15U
#define DISPLAY_BUFFER_LINE_1 0U
#define DISPLAY_BUFFER_LINE_2 1U
//===============================================================================================================

/****************************************************************************************************************
 * Display size parameters
*/
enum displayMovingDirection_enum{DISPLAY_CURRSOR_L, DISPLAY_CURRSOR_R, DISPLAY_MOVING_L, DISPLAY_MOVING_R};
//===============================================================================================================

/****************************************************************************************************************
 * Class for menage LCD display 
*/
class LCD_DataControl
{
private:
/*********************************************************************
 * Private variables for class
 */
uint8_t _idx_row, _idx_col, _cursor_direction;
uint8_t _arrDisplayData[DISPLAY_BUFFER_MAX_COL_AMOUT][DISPLAY_BUFFER_MAX_ROW_AMOUT];
//====================================================================

/**********************************************************************
 * Add and remove data from buffer
*/
uint8_t _PutDataBuffer(uint8_t data);
void _PrintTestData(void);
//====================================================================

public:
/*********************************************************************
 * Definitions for public class varibales 
*/
    LCD_DataControl(void);
    ~LCD_DataControl();

    void ClearData(void);
    void ReturnHome(void);
 
    inline uint8_t CursorCurrentLoc(void);
    inline uint8_t CursorSpaceToEnd(void);

    // Cursor movement menagment, LCD data displayed momvemt
    inline void SetMovingDirection(enum displayMovingDirection_enum direction);
    inline void SetCurrsorToPosition(uint8_t row_n, uint8_t col_n);

    // Print and delete data from array display. 
    // Both method return amount of characters that have been printed or deleted
    // due to current cursor position
    uint8_t PrintStr(const char pStr[], uint8_t strLen);
    uint8_t DeletStr(const char pStr[], uint8_t strLen);

    void CALL_Test1(void);
};
//==============================================================================================
#endif // ifndef LCD_DATA_CONTROL_H_
//==============================================================================================
#endif // ifdef CMP_X01_LCD_DATA_CONTROL_H
//==============================================================================================