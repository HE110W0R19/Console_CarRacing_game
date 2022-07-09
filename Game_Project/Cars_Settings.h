#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <random>
#include "Map_Settings.h"

class player_car_type_1
{
private:
    uint8_t spawn_cord_x = 72;
    uint8_t spawn_cord_y = 30;
protected:
    uint8_t car_x_size = 7;
    uint8_t car_y_size = 7;
public:
    char** _car = new char* [car_y_size] {};
    player_car_type_1()
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
                if (((i == 0 || i == 6) && (j >= 1 && j <= car_x_size - 2)))
                    _car[i][j] = 210;
                else if ((i == 1 || i == 5) && (j >= 1 && j <= car_x_size - 2))
                    _car[i][j] = 186;
                else if ((i >= 2 || i <= 4) && j == 0)
                    _car[i][j] = 198;
                else if ((i >= 2 || i <= 4) && j == 6)
                    _car[i][j] = 181;
                else
                    _car[i][j] = 219;
                _car[0][0] = 213; _car[6][0] = 212;//left bumper 
                _car[0][6] = 184; _car[6][6] = 190;//right bumper
                _car[1][0] = 219; _car[5][0] = 219;//left wheels
                _car[1][6] = 219; _car[5][6] = 219;//right wheels
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

class player_car_type_2 : public player_car_type_1
{
private:
    uint8_t spawn_cord_x = 72;
    uint8_t spawn_cord_y = 30;
public:
    void create_car(game_map& tmp_map)
    {
        // create car texture
        for (uint8_t i = 0; i < car_y_size; ++i)
        {
            for (uint8_t j = 0; j < car_x_size; ++j)
            {
                if (((i == 0 || i == 6) && (j >= 1 && j <= car_x_size - 2)))
                    _car[i][j] = 196;// peredniy bamper i zadniy
                else if ((i == 1 || i == 5) && (j >= 1 && j <= car_x_size - 2))
                    _car[i][j] = 179;//kapot i bagashnik
                else if ((i >= 2 || i <= 4) && j == 0)
                    _car[i][j] = 195;//bokovina levaya
                else if ((i >= 2 || i <= 4) && j == 6)
                    _car[i][j] = 180;// bokovina pravaya
                else
                    _car[i][j] = 178;
                _car[0][0] = 218; _car[6][0] = 192;//levie krilya 
                _car[0][6] = 191; _car[6][6] = 217;//pravie krilya
                _car[1][0] = 221; _car[5][0] = 221;//left wheels
                _car[1][6] = 222; _car[5][6] = 222;//right wheels
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
    }
};