#include "config.h"
#include "lcdWrite.h"
#include "writeGameplayArea.h"
#include <stdio.h>
void paddle_left(void)
{ 
    static uchar  y = 1;
    static uchar x, z = 0;
    static uchar Y = 5; // initial vertical position of the paddle
    static uchar X = 0; // initial horizontal position of the paddle
    bool upper_pos[8];//= {0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};
    bool start_pos[8];// = {0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};
    if(PORTAbits.RA4 == 0)              //left/ up button is pressed
    {
        for(z = 0; z < 8; z++)
        {
            upper_pos[z] = 0xff - (0xff >> z);
            start_pos[z] = 0xff >> z;
            //printf("upper_pos[%d] = %x\n", z, upper_pos[z]);
            //printf("start_pos[%d] = %x\n", z, start_pos[z]);    
        }
         /* gameplay_area[Y-y][0] = upper_pos[x];   // draw paddle above existing paddle position
          gameplay_area[Y][0] = start_pos[x];     // existing paddle moves upm one pixel per button press
          writeGameplayArea(); 
          x++;*/
        gameplay_area[Y-y][0] = upper_pos[x];
        gameplay_area[Y][0] = start_pos[x];
        writeGameplayArea(); 
         x++;
        if(x >= 9)
        {
            Y = Y - 1;
            x = 1;
        }
        printf("x = %d\n", x);
        printf("Y = %d\n", Y);
        printf("upper_pos = %x\n",upper_pos[x]);
        printf("start_pos = %x\n",start_pos[x]);
       
    }
}
