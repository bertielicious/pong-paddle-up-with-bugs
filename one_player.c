#include "config.h"
#include "clear_screen.h"
#include "set_game_area.h"
#include "draw_paddles.h"
#include "lcdWrite.h"
#include "draw_puck.h"
void one_player(void)
{
    clear_screen();
    set_game_area();
    draw_paddles();
    draw_puck();
}
