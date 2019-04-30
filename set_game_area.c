#include "config.h"
#include "lcdWrite.h"
void set_game_area(void)
{
    uchar divider_line = 0xcc;
    uchar puck = 0x3c; 
    uchar i, j ,k, x, y;  
    uchar x_offset = 6;
    uchar setx = 0;
    uchar sety = 0x40;
    
// draw upper game boundary line from x = 1 to x = 82, y = 0, byte written  = 0x01 from x = 1 to 82
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_Y|0x00, LOW);  // sets Y address at top row of LCD
    lcdWrite(SET_X, LOW);
    for (i = 1; i < 83; i++)
    {     
            lcdWrite(SET_X|i, LOW);
            lcdWrite(0x01, HIGH);
    }
    
    // draw lower game boundary line from x = 1 to x = 82, y = 5, byte written  = 0x80 from x = 1 to 82
    
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_Y|0x05, LOW);  // sets Y address at bottom row of LCD
    lcdWrite(SET_X, LOW);
    for (i = 1; i < 83; i++)
    {     
            lcdWrite(SET_X|i, LOW);
            lcdWrite(0x80, HIGH);
    }
    
    // draw mid-court boundary with dashed vertical line from x = 42, to x = 42, and from y = 0, to y = 5
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_X|42, LOW);    // x = 42 (mid point for net))
    lcdWrite(VERT_ADDR, LOW);   // vertical addressing mode
    
    for( j = 0; j < 6 ; j++)    // draw vertical line at column 42
    {      
      lcdWrite(SET_Y|j, LOW);  // sets address at top row of LCD)
      lcdWrite(puck, HIGH);     // writes a byte of 1's to LCD (--------)
    }
}