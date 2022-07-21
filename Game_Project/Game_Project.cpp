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
const uint8_t zone_front_size = 1;//front crush zone
const uint8_t zone_behind_size = 37;//behind crush zone

int main()
{
    /*setlocale(LC_ALL, "Rus");*/
    system("mode con cols=180 lines=50");//start console window size
    uint8_t car_move_cord_x = 72;
    uint8_t car_move_cord_y = 30;

    uint32_t car_speed = 1000;
    uint32_t car_score = 0;

    game_map test_map;
    player_car_type_1 test_car;
    game_road test_road;
    _city_buss_type1 test_buss1;

    test_road.create_road();
    test_car.create_car(test_map);
    test_buss1.create_buss(test_road);

    /*game_start_key();
    game_start_time();*/

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            switch (key)
            {
            case 'd':
                car_move_cord_x += 2;
                if (car_move_cord_x >= zone_right_size)
                {
                    Sleep(1200);
                    game_over_print();
                    return 0;
                }
                break;
            case 'a':
                car_move_cord_x -= 2;
                if (car_move_cord_x <= zone_left_size)
                {
                    Sleep(1200);
                    game_over_print();
                    return 0;
                }
                break;
            case 'w':
                --car_move_cord_y;
                car_score += 2;
                if (car_move_cord_y <= zone_front_size)
                {
                    ++car_move_cord_y;
                }
                break;
            case 's':
                car_move_cord_y+=2;
                car_score -= 2;//score -2 because S==brake and car stop
                if (car_move_cord_y >= zone_behind_size)
                {
                    --car_move_cord_y;
                    car_speed = 500;
                }
                break;
            default:

                break;
            }
        }
        //city cars
        if (car_score % 50 == 0) 
        {
            uint8_t spawn_cord_x = spawn_cords[Rand() % 9];
            test_buss1.add_buss_to_road(test_road,spawn_cord_x);
        }       
        //player car
        test_car.game_car_move(test_map, test_road,
            car_move_cord_x, car_move_cord_y); 
        if (car_speed > 0)
            car_speed -= 100;//speed up at start
        //player score
        car_score += 2;
        //print map
        game_map_draw(test_map);
        cout << "...Your Score:" << car_score << endl;
        //screan cleaner
        setcur(0, 0, car_speed);//3-num -> speed;
    } 
    system("pause");
    return 0;
}
