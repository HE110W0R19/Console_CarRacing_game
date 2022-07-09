#pragma once
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

const uint8_t road_y_size = 41;
const uint8_t road_x_size = 101;

class game_map
{
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
                    _map[i][j] = 176;                
            }
        }
        _map[0][0] = 201; _map[44][0] = 200;
        _map[0][169] = 187; _map[15][169] = 185;
        _map[0][130] = 203; _map[15][130] = 200;
        _map[44][169] = 188;
    }
    ~game_map() = default;
};

class game_road
{
protected:
    uint8_t spawn_cord_x = 10;
    uint8_t spawn_cord_y = 2;
public:
    char** _road = new char* [road_y_size] {};
    game_road()
    {
        for (uint16_t i = 0; i < road_y_size; ++i)
        {
            _road[i] = new char[road_x_size];
        }
    }
    void create_road(game_map& tmp_map)
    {
        for (uint8_t i = 0; i < road_y_size; ++i)
        {
            for (uint8_t j = 0; j < road_x_size; ++j)
            {
                if (j == 0 || j == road_x_size - 1 || j == 49 || j == 50)
                    _road[i][j] = 221;
                else if (j % 10 == 0 && i % 2 == 0)
                    _road[i][j] = 254;
                else              
                    _road[i][j] = ' ';             
            }
        }
        for (uint8_t i = 0, y = spawn_cord_y; i < road_y_size; ++i, ++y)
        {
            for (uint8_t j = 0, x = spawn_cord_x; j < road_x_size; ++j, ++x)
            {
                tmp_map._map[y][x] = _road[i][j];
            }
        }
    }
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

void game_road_draw(game_road& tmp)
{
    for (uint8_t i = 0; i < road_y_size; ++i)
    {
        for (uint8_t j = 0; j < road_x_size; ++j)
        {
            cout << tmp._road[i][j];
        }
        cout << endl;
    }
}