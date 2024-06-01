#include "LCD_data_control.h"
#ifdef CMP_X01_LCD_DATA_CONTROL_H
/*****************************************************************************************************
 * 
*/

char arrChar1[] = "RED:";
char arrChar2[] = "BLU:";
char arrChar3[] = "00:00:00";
char arrChar4[] = "X";
char arrChar5[] = "1234567890123456";

/*****************************************************************************************************
 * @name		void
 * @brief		void
 * @param[in]	void
 * @note		void
 * @return		void
 */
//====================================================================================================

/*****************************************************************************************************
 * @name		LCD_DataControl
 * @brief		Constructor for class LCD_DataControl
 * @param[in]	void
 * @note		void
 * @return		void
 */
LCD_DataControl::LCD_DataControl(void)
{
	uint8_t i;
	_idx_row = 0x00;
	_idx_col = 0x00;
	_cursor_direction = DISPLAY_CURRSOR_L;

	ClearData();
}
//====================================================================================================

/*****************************************************************************************************
 * @name		LCD_DataControl
 * @brief		Deconstructor for class LCD_DataControl
 * @param[in]	void
 * @note		void
 * @return		void
 */
LCD_DataControl::~LCD_DataControl(){;}
//====================================================================================================

/*****************************************************************************************************
 * @name		_PutData
 * @brief		void
 * @param[in]	data Input data 
 * @note		void
 * @return		Status if data was added
 */
 uint8_t LCD_DataControl::_PutDataBuffer(uint8_t data)
 {
	if(_idx_row < DISPLAY_BUFFER_MAX_ROW_AMOUT) 
	{
		_arrDisplayData[_idx_col][_idx_row] = data;
		_idx_row++;

		return TRUE;
	}
	else
	{
		if(_idx_col == DISPLAY_BUFFER_LINE_1)
		{
			_idx_row = 0;
			_idx_col = DISPLAY_BUFFER_LINE_2;
			_PutDataBuffer(data);
		} 
		else{;}
	}
	return FALSE; 
 }
//====================================================================================================

/*****************************************************************************************************
 * @name		_ClearData
 * @brief		Clear LCD data buffer 
 * @param[in]	void
 * @note		void
 */
void LCD_DataControl::ClearData(void)
{
	uint8_t i, j;

	_idx_row = 0;
	_idx_col = 0;

	for(j=0; j<DISPLAY_BUFFER_MAX_COL_AMOUT; j++)
	{	for(i=0; i<DISPLAY_BUFFER_MAX_ROW_AMOUT; i++)
		{	_arrDisplayData[j][i] = 0x00; }}
}
//====================================================================================================

/*****************************************************************************************************
 * @name		_ReturnHome
 * @brief		Return cursor to start position
 * @param[in]	void
 * @note		void
 */
void LCD_DataControl::ReturnHome(void)
{
	_idx_row = 0;
	_idx_col = 0;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		SetDirection
 * 
 * @brief		Assign cursor or display movement moving direction
 * 
 * @param[in]	direction Input direction of type displayMovingDirection_enum
 *
 * @note		This function is using predefined macros
 * 				Method working OK
 */
inline void LCD_DataControl::SetMovingDirection(enum displayMovingDirection_enum direction)
{	
	_cursor_direction = direction;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		CursorCurrentLoc
 * @brief		Gets amout of characters from current cursor place to begin of LCD
 * @param[in]	void
 * @note		
 * @return		Amount of characters from current place to begin of LCD
 */
inline uint8_t LCD_DataControl::CursorCurrentLoc(void)
{
	return (_idx_row + 1);
}
//====================================================================================================

/*****************************************************************************************************
 * @name		CursorSpaceToEnd
 * @brief		Gets amout of characters from current cursor place end of LCD
 * @param[in]	void
 * @note		
 * @return		Amount of characters from current place to end of LCD
 */
inline uint8_t LCD_DataControl::CursorSpaceToEnd(void)
{
	return (DISPLAY_BUFFER_MAX_ROW_AMOUT - _idx_row);
}
//====================================================================================================

/*****************************************************************************************************
 * @name		SetCurrsorToPosition
 * @brief		Cursor is placed to certain position
 * 
 * @param[in]	row_n Certain row is set 
 * @param[in]	col_n Certain col is set
 * 
 * @note		Data is set when input atays in range
 */
void LCD_DataControl::SetCurrsorToPosition(uint8_t row_n, uint8_t col_n)
{
	if(col_n < DISPLAY_BUFFER_MAX_COL_AMOUT)
	{	_idx_col = col_n; }
	else{;}

	if(row_n < DISPLAY_BUFFER_MAX_ROW_AMOUT)
	{	_idx_row = row_n; }
	else{;}
}
//====================================================================================================

/*****************************************************************************************************
 * @name		PrintStr
 * @brief		Print array of characters on LCD screen
 * 
 * @param[in]	pStr Constatnt array of pointers to pint on LCD screen
 * @param[in]	strLen Lenght of a constant array of characters
 * 
 * @note		Amount of characters that will not be printed return as uint8_t
 * 				To print on certain place method SetCurrsorToPosition need to be used
 * @return		Amout of printed characters
 */
uint8_t LCD_DataControl::PrintStr(const char pStr[], uint8_t strLen)
{
	uint8_t i, iMAX;

	iMAX = CursorSpaceToEnd();
	if(iMAX > DISPLAY_BUFFER_MAX_ROW_AMOUT) {return 0;}
	else{;}

	SetMovingDirection(DISPLAY_CURRSOR_R);

	if(strLen > iMAX)
	{	strLen = iMAX;}
	else{;}

	for(i=0; i<strLen; i++)
	{
		_arrDisplayData[_idx_col][_idx_row] = pStr[i];
		_idx_row++;
	}

	if(_idx_row > DISPLAY_BUFFER_CURRSOR_IDX_END)
	{	_idx_row = DISPLAY_BUFFER_CURRSOR_IDX_END;}
	else{;}

	return strLen;
}
//====================================================================================================

/*****************************************************************************************************
 * @name		DeletStr
 * @brief		Print array of characters on LCD screen
 * 
 * @param[in]	pStr Constatnt array of pointers to pint on LCD screen
 * @param[in]	strLen Lenght of a constant array of characters
 * 
 * @note		Amount of characters that will not be printed return as uint8_t
 * 				To print on certain place method SetCurrsorToPosition need to be used
 * @return		Amout of printed characters
 */
uint8_t LCD_DataControl::DeletStr(const char pStr[], uint8_t strLen)
{
	uint8_t i, iMAX;

	iMAX = CursorCurrentLoc();
	if(iMAX > DISPLAY_BUFFER_MAX_ROW_AMOUT) {return 0;}
	else{;}

	SetMovingDirection(DISPLAY_CURRSOR_L);

	if(strLen > iMAX)
	{	strLen = iMAX;}
	else{;}

	for(i=0; i<strLen; i++)
	{
		_arrDisplayData[_idx_col][_idx_row] = pStr[i];
		_idx_row--;
	}

	if(_idx_row > DISPLAY_BUFFER_CURRSOR_IDX_END)
	{	_idx_row = DISPLAY_BUFFER_CURRSOR_IDX_END;}
	else{;}

	return strLen;
}
//====================================================================================================
void LCD_DataControl::_PrintTestData(void)
{
	uint8_t i;

	printf("Line0: %s \n", &arrChar5);

	printf("Line1: ");
	for(i=0; i<16; i++)
	{	putchar(_arrDisplayData[0][i]);}
	printf(" \n");

	printf("Line2: ");
	for(i=0; i<16; i++)
	{	putchar(_arrDisplayData[1][i]);}
	printf(" \n");
}

void LCD_DataControl::CALL_Test1()
{
	uint8_t charsPrinted;

	SetCurrsorToPosition(15,	DISPLAY_BUFFER_LINE_1);
	charsPrinted = DeletStr(arrChar5, 16);

	SetCurrsorToPosition(0,		DISPLAY_BUFFER_LINE_2);
	charsPrinted = PrintStr(arrChar5, 16);
	charsPrinted = PrintStr(arrChar3, 8);

	_PrintTestData();
}
//====================================================================================================
#endif // CMP_X01_LCD_DATA_CONTROL_H
//====================================================================================================