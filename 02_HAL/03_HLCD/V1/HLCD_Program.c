#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLCD_Private.h"
#include <avr/delay.h>

static u8 mode4Bit = 0;
static u8 mode8Bit = 0;
static u8 CGRamCharCounter = 0;


void HLCD_VoidSendData(u8 Copy_U8Data)
{
    if(mode8Bit)
    {
        /* RW = 0 to write to the LCD */
        MDIO_VoidSetPinValue(PORTB, RW, WRITE);
        /* RS = 1 to write on the data register. */
        MDIO_VoidSetPinValue(PORTB, RS, DR);
        /* Send Data */
        MDIO_VoidSetPortValue(PORTC, Copy_U8Data);
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
    }
    if(mode4Bit)
    {
        /* RW = 0 to write to the LCD */
        MDIO_VoidSetPinValue(PORTB, RW, WRITE);
        /* RS = 1 to write on the data register (DR). */
        MDIO_VoidSetPinValue(PORTB, RS, DR);

        /** Send Data **/
        /* first part */
        MDIO_VoidSetPortValue(PORTC, (Copy_U8Data & 0b11110000));
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
        /* second part */
        MDIO_VoidSetPortValue(PORTC, (Copy_U8Data & 0b00001111) << 4);
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
    }
}
void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
    if(mode8Bit)
    {
        /* RW = 0 to write to the LCD */
        MDIO_VoidSetPinValue(PORTB, RW, WRITE);
        /* RS = 0 to write on the instruction register */
        MDIO_VoidSetPinValue(PORTB, RS, IR);
        /* Send command */
        MDIO_VoidSetPortValue(PORTC, Copy_U8Command);
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
    }
    if(mode4Bit)
    {
        /* RW = 0 to write to the LCD */
        MDIO_VoidSetPinValue(PORTB, RW, WRITE);
        /* RS = 1 to write on the data register (DR). */
        MDIO_VoidSetPinValue(PORTB, RS, IR);

        /** Send Command **/
        /* first part */
        MDIO_VoidSetPortValue(PORTC, Copy_U8Command);
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
        /* second part */
        MDIO_VoidSetPortValue(PORTC, Copy_U8Command << 4);
        /* Enable */
        MDIO_VoidSetPinValue(PORTB, EN, HIGH);
        _delay_ms(2);
        MDIO_VoidSetPinValue(PORTB, EN, LOW);
        _delay_ms(2);
    }
}

/* I know this function looks silly and doesn't do much. why not call sendData directly right?
 * Well, I used it for semantic reason. because sometimes we sendData that is not chars to be displayed
 * maybe for example we are writing to the CGRAM. So I want to make sure that the user knows what he is
 * doing when he calls sendData, otherwise if he has no clue what to do and all that he wants is to
 * print a char to the LCD, then just call PrintChar
 * Not sure yet if this reasoning suffice for such a funtion or not.*/
void HLCD_VoidPrintChar(u8 Copy_U8Char)
{
	HLCD_VoidSendData(Copy_U8Char);
}

void HLCD_VoidPrintCharXY(u8 Copy_U8Char, u8 Copy_U8X, u8 Copy_U8Y)
{
	if( Copy_U8Y == 0)
	{
		HLCD_VoidSendCommand(0b10000000 + 0x40 + Copy_U8X); //0x40 to start in the second line y == 0
		HLCD_VoidSendData(Copy_U8Char);
	}
	else if (Copy_U8Y == 1)
	{
		HLCD_VoidSendCommand(0b10000000 + Copy_U8X);
		HLCD_VoidSendData(Copy_U8Char);
	}
}

void HLCD_VoidPrintString(u8 *Copy_U8String)
{
    for(u32 i = 0; Copy_U8String[i] != '\0' ; i++)
        HLCD_VoidSendData(Copy_U8String[i]);
}

void HLCD_VoidPrintStringXY(u8 *Copy_U8String, u8 Copy_U8X, u8 Copy_U8Y)
{
	if( Copy_U8Y == 0)
	{
		HLCD_VoidSendCommand(0b10000000 + 0x40 + Copy_U8X); //0x40 to start in the second line y == 0
		HLCD_VoidPrintString(Copy_U8String);
	}
	else if (Copy_U8Y == 1)
	{
		HLCD_VoidSendCommand(0b10000000 + Copy_U8X);
		HLCD_VoidPrintString(Copy_U8String);
	}

}

void HLCD_VoidSendNumber(u32 Copy_U32Number)
{
    u32 LOC_U32ReversedNumber = 1;
    if(0 == Copy_U32Number)
        HLCD_VoidPrintChar('0');
    else
    {
        /* Loop to reverse the number */
        while(Copy_U32Number > 0)
        {
            LOC_U32ReversedNumber = (LOC_U32ReversedNumber * 10) + (Copy_U32Number % 10);
            Copy_U32Number /= 10;
        }

        /* Loop to print the number reversed for the second time */
        u32 LOC_U32Number;
        while(LOC_U32ReversedNumber > 1)
        {
            LOC_U32Number = LOC_U32ReversedNumber % 10;
            HLCD_VoidPrintChar(LOC_U32Number + '0');
            LOC_U32ReversedNumber /= 10;
        }
    }
}

/* returns the value of the AC*/
u8 HLCD_U8ReadAdressCounter(void)
{
	u8 LOC_U8AdressCounter;
	/* set the direction of the port as input temporarily*/
    MDIO_VoidSetPortDirection(PORTC, 0);
	MDIO_VoidSetPortValue(PORTC, 0); //disable pull-up resistors
	/* set RW to read and RS to IR to read address counter */
	MDIO_VoidSetPinValue(PORTB, RW, READ);
	MDIO_VoidSetPinValue(PORTB, RS, IR);
	/* set EN  to high to read data */
	MDIO_VoidSetPinValue(PORTB, EN, HIGH);
	/* only get the 7 bits of the address counter. ignore the 8th bit "busy bit" */
	/* get the address counter value */
	LOC_U8AdressCounter =   (MDIO_U8GetPortValue(PORTC) & 0b01111111);
	/* set the direction back to output */
    MDIO_VoidSetPortDirection(PORTC, 0xff);
	return LOC_U8AdressCounter;
}

/* returns Char code that can be written in DDRAM and displayed on the LCD*/
/* did not handle yet if the user Loads more than 8 chars into the cgRAM*/
u8 HLCD_U8LoadCustm8ByteChar(u8 *symbol)
{
	/* Get the AC before calling this function*/
	u8 LOC_U8AdressCounterTemp = HLCD_U8ReadAdressCounter();
	/* set the AC to point to the appropriate address in CG RAM*/
	HLCD_VoidSendCommand(0b01000000 + 8 * CGRamCharCounter);
	/* write or custom char to the CGRAM*/
	/* The AC automatically increases by one so we don't need to set the AC
	 * every iteration of the for loop*/
	for(u8 i = 0; i < 8; i++)
		HLCD_VoidSendData(symbol[i]);
	/* return the address counter to point to whatever it was pointing to in the DDRAM
	 * before calling this function */
	HLCD_VoidSendCommand(0b10000000 + LOC_U8AdressCounterTemp);
	CGRamCharCounter++;
	return (CGRamCharCounter-1);
}

void HLCD_VoidDispClr(void)
{
    HLCD_VoidSendCommand(0b00000001);
}

void HLCD_VoidSetCursorXY(u8 Copy_U8X, u8 Copy_U8Y)
{
	if( Copy_U8Y == 0)
		HLCD_VoidSendCommand(0b10000000 + 0x40 + Copy_U8X); //0x40 to start in the second line y == 0
	else if (Copy_U8Y == 1)
		HLCD_VoidSendCommand(0b10000000 + Copy_U8X);
}


void HLCD_Void8BitModeInit(void)
{
    mode4Bit = 0;
    mode8Bit = 1;
    /* set directions */
    MDIO_VoidSetPortDirection(PORTC, 0xff);
    MDIO_VoidSetPinDirection(PORTB, RS, OUTPUT);
    MDIO_VoidSetPinDirection(PORTB, RW, OUTPUT);
    MDIO_VoidSetPinDirection(PORTB, EN, OUTPUT);

    /** Initialization sequence **/
    /* wait for more than 30ms after voltage rises to 4.5v */
    _delay_ms(40);
    /* function set */
    HLCD_VoidSendCommand(0b00111000);
    /* wait for more than 39us */
    _delay_us(100);
    /* Display on/off with no cursor and no blinking*/
    HLCD_VoidSendCommand(0b00001100);
    /* wait for more than 39us */
    _delay_us(100);
    /* Display Clear */
    HLCD_VoidSendCommand(0b00000001);
    /* wait for more than 1.53ms */
    _delay_ms(2);
    /* Entry mode set*/
    HLCD_VoidSendCommand(0b00000110);

}
void HLCD_Void4BitModeInit(void)
{
    mode8Bit = 1;
    mode4Bit = 0;
    /* set directions */
    MDIO_VoidSetPortDirection(PORTC, 0xff);
    MDIO_VoidSetPinDirection(PORTB, RS, OUTPUT);
    MDIO_VoidSetPinDirection(PORTB, RW, OUTPUT);
    MDIO_VoidSetPinDirection(PORTB, EN, OUTPUT);

    /** Initialization sequence **/
    /* wait for more than 30ms after voltage rises to 4.5v */
    _delay_ms(40);
    /* function set */
    HLCD_VoidSendCommand(0b00100000);
    HLCD_VoidSendCommand(0b00100000);
    HLCD_VoidSendCommand(0b10000000);
    /* wait for more than 39us */
    _delay_us(100);
    /* Display on/off with no cursor and no blinking*/
    HLCD_VoidSendCommand(0b00000000);
    HLCD_VoidSendCommand(0b11000000);
    /* wait for more than 39us */
    _delay_us(100);
    /* Display Clear */
    HLCD_VoidSendCommand(0b00000000);
    HLCD_VoidSendCommand(0b00010000);
    /* wait for more than 1.53ms */
    _delay_ms(2);
    /* Entry mode set */
    HLCD_VoidSendCommand(0b00000000);
    HLCD_VoidSendCommand(0b01100000);

    mode8Bit = 0;
    mode4Bit = 1;
}
