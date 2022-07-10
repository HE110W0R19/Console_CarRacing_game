#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <random>
#include "Map_Settings.h"
#include "Cars_Settings.h"

using namespace std;

int main()
{
    system("mode con cols=180 lines=50");
    /*setlocale(LC_ALL, "Rus");*/
    game_map test_map;
    player_car_type_1 test_car;
    game_road test_road;
    test_road.create_road(test_map);
    test_car.create_car(test_map);
    game_map_draw(test_map);
    /*game_road_draw(test_road);*/
    system("pause");
    return 0;
}
