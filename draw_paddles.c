#include "config.h"
#include "writeGameplayArea.h"
void draw_paddles(void)
{
    uchar Y = 5;
    gameplay_area[Y][0] = paddle;   // draw paddle starting position on row 3 column 0
    writeGameplayArea(); 
}
