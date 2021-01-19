
#include "gb/gb.h"
#include "gbt_player.h"

// #include "dancing_nanner.c"
#include "circle_swell.c"
#include "rotating_smiley.c"

extern const unsigned char * song_Data[];

void update_sprites(UINT8 index, UINT8 xx, UINT8 yy)
{
    set_sprite_tile(0, 0 + index);
    set_sprite_tile(1, 4 + index);
    set_sprite_tile(2, 8 + index);
    set_sprite_tile(3, 12 + index);

    move_sprite(0, xx, yy);
    move_sprite(1, xx + 8, yy);
    move_sprite(2, xx, yy + 8);
    move_sprite(3, xx + 8, yy + 8);
}

void performant_delay(UINT8 numloops)
{
    UINT8 i;

    for (i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }
}

void main()
{    
    UINT8 index;
    UINT8 counter;
    UINT8 animation_counter;
    UINT8 x;
    UINT8 y;

    animation_counter = 0;
    counter = 0;
    index = 0;
    x = 40;
    y = 40;

    /*
        music stuff
    */    
    disable_interrupts();

    gbt_play(song_Data, 2, 7);
    gbt_loop(1);

    set_interrupts(VBL_IFLAG);
    enable_interrupts();

    /*
        sprite stuff
    */

    set_sprite_data(0, 16, circleswell);

    set_sprite_data(17, 4, rotatingsmiley);

    SHOW_SPRITES;

    while (1)
    {
        wait_vbl_done();

        // your game code here
        animation_counter++;

        if (animation_counter >= 8)
        {
            index++;

            if (index == 4)
            {
                index = 0;

                switch (counter)
                {
                    case 0:
                        x = 40;
                        y = 40;
                        break;

                    case 1:
                        x = 120;
                        y = 40;
                        break;

                    case 2:
                        x = 40;
                        y = 110;
                        break;

                    case 3:
                        x = 120;
                        y = 110;
                        break;
                }

                counter++;

                if (counter > 3)
                {
                    counter = 0;
                }
            }

            update_sprites(index, x, y);

            set_sprite_tile(4, 17 + index);

            move_sprite(4, 80, 80 + (index % 2) * 6);

            animation_counter = 0;
        }
       
        // performant_delay(10);

        gbt_update(); // This will change to ROM bank 1.
    }
}
