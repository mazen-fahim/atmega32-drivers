#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_


/* Initialization */
void HLCD_Void8BitModeInit(void);
void HLCD_Void4BitModeInit(void);

/* Write to Data and Instruction Registers */
void HLCD_VoidSendData(u8 Copy_U8Data);
void HLCD_VoidSendCommand(u8 Copy_U8Command);

/* Print to LCD*/
void HLCD_VoidPrintChar(u8 Copy_U8Char);
void HLCD_VoidPrintCharXY(u8 Copy_U8Char, u8 Copy_U8X, u8 Copy_U8Y);
void HLCD_VoidPrintString(u8 *Copy_U8String);
void HLCD_VoidPrintStringXY(u8 *Copy_U8String, u8 Copy_U8X, u8 Copy_U8Y);
void HLCD_VoidSendNumber(u32 Copy_U32Number);

/** General commands **/
/* Returns the content of the AC*/
u8 HLCD_U8ReadAdressCounter(void);
/* Returns the char code of the custom char*/
u8 HLCD_U8LoadCustm8ByteChar(u8 *symbol);
void HLCD_VoidDispClr();
void HLCD_VoidSetCursorXY(u8 Copy_U8X, u8 Copy_U8Y);


#endif
