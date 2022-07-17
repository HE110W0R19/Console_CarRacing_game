#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "Map_Settings.h"
#include "Cars_Settings.h"

using namespace std;

void setcur(int x, int y)//screan clear
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

int main()
{
    /*setlocale(LC_ALL, "Rus");*/
    system("mode con cols=180 lines=50");
    uint8_t car_move_cord_x = 72;
    uint8_t car_move_cord_y = 30;

    game_map test_map;
    player_car_type_1 test_car;
    game_road test_road;

    test_road.create_road(test_map);
    test_car.create_car(test_map);

    while (true) 
    {   
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'd' || key == 'D')
                car_move_cord_x+=2;
            if (key == 'a' || key == 'A')
                car_move_cord_x-=2;
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
