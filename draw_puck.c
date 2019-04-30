#include "config.h"
#include "lcdWrite.h"
#include "writeGameplayArea.h"
void draw_puck(void)
{
    uchar row, col = 0;
    row = 0;
    lcdWrite(VERT_ADDR, LOW);
    lcdWrite(SET_Y|row, LOW);
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_X|col, LOW);
    for(col = 0; col < 8; col++)
    {
        gameplay_area[row][col] = BALL[col];    // write BALL data into the gameplay_area array
        writeGameplayArea();
    }
}
