#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "Map_Settings.h"
#include "Cars_Settings.h"
#include "Game_Menu_Settings.h"

using namespace std;

//game zone sizes
const uint8_t zone_left_size = 16;//left crush zone
const uint8_t zone_right_size = road_x_size-3;//right crush zone

int main()
{
    /*setlocale(LC_ALL, "Rus");*/
    system("mode con cols=180 lines=50");//start console window size
    uint8_t car_move_cord_x = 72;
    uint8_t car_move_cord_y = 30;

    game_map test_map;
    player_car_type_1 test_car;
    game_road test_road;

    test_road.create_road();
    test_car.create_car(test_map);

    game_start_time();
    while (true) 
    {   
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'd' || key == 'D')
            {
                car_move_cord_x += 2;
                if (car_move_cord_x >= zone_right_size)
                {
                    Sleep(1200);
                    game_over_print();
                    return 0;
                }
            }
            if (key == 'a' || key == 'A')
            {
                car_move_cord_x -= 2;
                if (car_move_cord_x <= zone_left_size)
                {
                    Sleep(1200);
                    game_over_print();
                    return 0;
                }
            }
            if (key == 'w' || key == 'W')
                --car_move_cord_y;
            if (key == 's' || key == 'S')
                ++car_move_cord_y;
        }       
        test_car.game_car_move(test_map, test_road,
            car_move_cord_x, car_move_cord_y);
        game_map_draw(test_map);
        setcur(0, 0);
    }
    system("pause");
    return 0;
}
