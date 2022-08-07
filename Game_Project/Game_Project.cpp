#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "Map_Settings.h"
#include "Cars_Settings.h"
#include "Game_Menu_Settings.h"

using namespace std;
// w,a,s,d - car move // p - pause // 
//game zone sizes
const uint8_t zone_left_size = 16;//left crush zone
const uint8_t zone_right_size = road_x_size-3;//right crush zone
const uint8_t zone_front_size = 1;//front game zone
const uint8_t zone_behind_size = 37;//behind game zone

vector<int> difficulty_level{70,50,25};//0-easy 1-medium 2-hard
int difficulty_choise = 0;

int main()
{
    /*setlocale(LC_ALL, "Rus");*/
    system("mode con cols=180 lines=50");//start console window size
    uint8_t car_move_cord_x = 72;
    uint8_t car_move_cord_y = 30;

    uint8_t spawn_cord_x_buss = 0; uint8_t spawn_cord_y_buss = 0;
    uint8_t spawn_cord_x_car = 0; uint8_t spawn_cord_y_car = 0;

    uint32_t car_speed = 1000;
    uint32_t car_score = 0;

    game_map player_map;
    player_car_type_1 _car;
    game_road _road;
    _city_buss_type1 _bot_buss1;
    _city_car_type1 _bot_car1;

    _road.create_road();
    _car.create_car(player_map);
    _bot_buss1.create_buss(_road);
    _bot_car1.create_car(player_map);
    
    game_start_menu(difficulty_choise);
    game_start_key();
    game_start_time();

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
                car_move_cord_y += 2;
                car_score -= 2;//score -2 because S==brake and car stop
                if (car_move_cord_y >= zone_behind_size)
                {
                    car_move_cord_y -= 2;
                    car_speed = 500;
                }
                break;
            case 'p':
                game_start_key();
                system("cls");
                break;
            default:

                break;
            }
        }
        //add_city cars
        if (car_score % difficulty_level[difficulty_choise] == 0)
        {
            uint8_t car_amount = 3;
            uint8_t i = 0;
            for (; i < car_amount; ++i)
            {
                spawn_cord_x_buss = spawn_cords_x[Rand() % 8];
                spawn_cord_y_buss = spawn_cords_y[Rand() % 3];
                spawn_cord_x_car = spawn_cords_x[Rand() % 8];
                spawn_cord_y_car = spawn_cords_y[Rand() % 3];
                if (spawn_cord_x_buss != spawn_cord_x_car && spawn_cord_y_buss != spawn_cord_y_car)
                {
                    _bot_car1.add_car_to_road(_road, spawn_cord_x_car, spawn_cord_y_car);
                    _bot_buss1.add_buss_to_road(_road, spawn_cord_x_buss, spawn_cord_y_buss);
                }
                else
                    --i;
            }           
        }
        //player car
        _car.game_car_move(player_map, _road,
            car_move_cord_x, car_move_cord_y);
        if (car_speed > 0)
            car_speed -= 100;//speed up at start
        //player score
        car_score += 2;
        //print map
        game_map_draw(player_map);
        cout << "...Your Score:" << car_score << endl;
        //screan cleaner
        _road.clear_road();
        setcur(0, 0, car_speed);//3-num -> speed;
    }
    system("pause");
    return 0;
}
