#include "STD_TYPES.h"
#include "../../03_MCAL/01_MDIO/V1/MDIO_Interface.h"
#include "HKPD_Config.h"
#include "HKPD_Privat.h"
#include "HKPD_Private.h"


void KPD_VoidInit(void)
{
    /* columns */
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_COLUMN0_PIN, OUTPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_COLUMN1_PIN, OUTPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_COLUMN2_PIN, OUTPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_COLUMN3_PIN, OUTPUT);
    MDIO_VoidSetPinValue(KPD_PORT, KPD_COLUMN0_PIN, LOW);
    MDIO_VoidSetPinValue(KPD_PORT, KPD_COLUMN1_PIN, LOW);
    MDIO_VoidSetPinValue(KPD_PORT, KPD_COLUMN2_PIN, LOW);
    MDIO_VoidSetPinValue(KPD_PORT, KPD_COLUMN3_PIN, LOW);

    /* rows */
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_ROW0_PIN, INPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_ROW1_PIN, INPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_ROW2_PIN, INPUT);
    MDIO_VoidSetPinDirection(KPD_PORT, KPD_ROW3_PIN, INPUT);
    MDIO_VoidActivatePinInternalPullupResistor(KPD_PORT, KPD_ROW0_PIN); 
    MDIO_VoidActivatePinInternalPullupResistor(KPD_PORT, KPD_ROW1_PIN); 
    MDIO_VoidActivatePinInternalPullupResistor(KPD_PORT, KPD_ROW2_PIN); 
    MDIO_VoidActivatePinInternalPullupResistor(KPD_PORT, KPD_ROW3_PIN); 
    
}
u8 KPD_U8GetPressedKey(void) {
    u8 LOC_U8PressedKey = KPD_NO_PRESSED_KEY;
    u8 LOC_U8ColumnIndex, LOC_U8RowIndex, LOC_U8PinState;
    /* this differs for every application so we have to provide a way for the user to configure its values*/
    static u8 LOC_U8Arr[4][4] = KPD_ARR_VAL;

    static u8 LOC_U8KPDColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static u8 LOC_U8KPDRowArr[ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    for(LOC_U8ColumnIndex = 0; LOC_U8ColumnIndex < COLUMN_NUM; LOC_U8ColumnIndex++)
    {
        /* Activate current column */
        MDIO_VoidSetPinValue(KPD_PORT, LOC_U8KPDColumnArr[LOC_U8ColumnIndex], LOW);

        for(LOC_U8RowIndex = 0; LOC_U8RowIndex < ROW_NUM; LOC_U8RowIndex++)
        {
            /* Read the current row*/
            LOC_U8PinState = MDIO_U8GetPinValue(KPD_PORT, LOC_U8KPDRowArr[LOC_U8RowIndex]);

            /* Check if switch is Pressed*/
            if(LOC_U8PinState == LOW)
            {
                LOC_U8PressedKey = LOC_U8Arr[LOC_U8RowIndex][LOC_U8ColumnIndex];
                
                /* Polling: Busy waiting until the key is released */
                while(LOC_U8PinState == LOW)
                    LOC_U8PinState = MDIO_U8GetPinValue(KPD_PORT, LOC_U8KPDRowArr[LOC_U8RowIndex]);

                return LOC_U8PressedKey; 
            }
        }
        /* Deactivate current column */
        MDIO_VoidSetPinValue(KPD_PORT, LOC_U8KPDColumnArr[LOC_U8ColumnIndex], HIGH);
    }
    return LOC_U8PressedKey;
}
