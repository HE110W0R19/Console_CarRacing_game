#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <random>

using namespace std;
random_device Rand;
//game map sizes
const uint8_t map_y_size = 45;
const uint8_t map_x_size = 170;

class game_map   
{
protected:
    
public:
    char** _map = new char* [map_y_size] {};
    game_map()
    {
        for (uint16_t i = 0; i < map_y_size; ++i)
        {
            _map[i] = new char[map_x_size];
        }
        for (uint16_t i = 0; i < map_y_size; ++i)
        {
            for (uint16_t j = 0; j < map_x_size; ++j)
            {
                if ((i == 0 || i == map_y_size - 1) || (j >= 130 && i == 15))
                    _map[i][j] = 205;
                else if ((j == 130 && i <= 15) || (j == 0) || (j == map_x_size - 1))
                    _map[i][j] = 186;
                else
                {
                    _map[i][j] = ' ';
                }
            }
        }
        _map[0][0] = 201; _map[44][0] = 200;
        _map[0][169] = 187; _map[15][169] = 185;
        _map[0][130] = 203; _map[15][130] = 200;
        _map[44][169] = 188;
    }
    ~game_map() = default;
};

class game_car
{
private:
    uint8_t spawn_cord_x = 70;
    uint8_t spawn_cord_y = 30;
protected:
    uint8_t car_x_size = 5;
    uint8_t car_y_size = 5;
public:
    char** _car = new char* [car_y_size] {};
    game_car()
    {
        for (uint8_t i = 0; i < car_y_size; ++i)
        {
            _car[i] = new char[car_x_size];
        }
    }

    virtual void create_car(game_map& tmp_map)
    {
        //create car texture
        for (uint8_t i = 0; i < car_y_size; ++i)
        {
            for (uint8_t j = 0; j < car_x_size; ++j)
            {
                _car[i][j] = 219;
            }
        }
        //add car to map
        for (uint8_t i = 0, y = spawn_cord_y; i < car_y_size; ++i, ++y)
        {
            for (uint8_t j = 0, x = spawn_cord_x; j < car_x_size; ++j, ++x)
            {
                tmp_map._map[y][x] = _car[i][j];
            }
        }
    };
};

void game_map_draw(game_map& tmp)
{
    for (uint8_t i = 0; i < map_y_size; ++i)
    {
        for (uint8_t j = 0; j < map_x_size; ++j)
        {
            cout << tmp._map[i][j];
        }
        cout << endl;
    }
}

int main()
{
    /*setlocale(LC_ALL, "Rus");*/
    game_map test_map;
    game_car test_car;
    test_car.create_car(test_map);
    game_map_draw(test_map);
    system("pause");
    return 0;
}
