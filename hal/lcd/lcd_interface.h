#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Initialization */
void LCD_Void8BitModeInit(void);
void LCD_Void4BitModeInit(void);

/* Write to Data and Instruction Registers */
void LCD_VoidSendData(u8 Copy_U8Data);
void LCD_VoidSendCommand(u8 Copy_U8Command);

/* Print to LCD*/
void LCD_VoidPrintChar(u8 Copy_U8Char);
void LCD_VoidPrintCharXY(u8 Copy_U8Char, u8 Copy_U8X, u8 Copy_U8Y);
void LCD_VoidPrintString(u8 *Copy_U8String);
void LCD_VoidPrintStringXY(u8 *Copy_U8String, u8 Copy_U8X, u8 Copy_U8Y);
void LCD_VoidSendNumber(u32 Copy_U32Number);

/** General commands **/
/* Returns the content of the AC*/
u8 LCD_U8ReadAdressCounter(void);
/* Returns the char code of the custom char*/
u8 LCD_U8LoadCustm8ByteChar(u8 *symbol);
void LCD_VoidDispClr();
void LCD_VoidSetCursorXY(u8 Copy_U8X, u8 Copy_U8Y);

#endif
