#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Map_Settings.h"
#include "Game_Menu_Settings.h"

random_device Rand;

//car1==================================================
class player_car_type_1
{
private:
    uint8_t default_spawn_cord_x = 72;
    uint8_t default_spawn_cord_y = 30;
protected:
    uint8_t car_x_size = 7;
    uint8_t car_y_size = 7;
public:
    vector<vector<char> > _car;
    player_car_type_1();    
    virtual void create_car(game_map& tmp_map);
    virtual void game_car_move(game_map& tmp_map, game_road& tmp_road,
        uint8_t _car_cord_x, uint8_t _car_cord_y);
};

inline player_car_type_1::player_car_type_1()
{
    for (uint8_t i = 0; i < car_y_size; ++i)
    {
        std::vector<char> temp;
        for (uint8_t j = 0; j < car_x_size; ++j)
            temp.push_back(' ');
        _car.push_back(temp);
    }
}

inline void player_car_type_1::create_car(game_map& tmp_map)
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
}

inline void player_car_type_1::game_car_move(game_map& tmp_map, game_road& tmp_road,
    uint8_t _car_cord_x, uint8_t _car_cord_y)
{
    ////road animation
    tmp_road.road_animation();
    ////add road to map
    tmp_road.add_road_to_map(tmp_map);
    //add car to road
    for (uint8_t i = 0, y = _car_cord_y; i < car_y_size; ++i, ++y)
    {
        for (uint8_t j = 0, x = _car_cord_x; j < car_x_size; ++j, ++x)
        {
            tmp_map._map[y][x] = _car[i][j];
        }
    }
}
//car 2===============================================
class player_car_type_2 : public player_car_type_1
{
private:
    uint8_t default_spawn_cord_x = 72;
    uint8_t default_spawn_cord_y = 30;
public:
    void create_car(game_map& tmp_map);
};

void player_car_type_2::create_car(game_map& tmp_map)
{
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
    }
}

//for city bot cars
vector<int> spawn_cords{ 12,22,32,42,52,62,72,82 };

class _city_buss_type1
{
private:
    uint8_t spawn_cord_y = 1;
protected:
    uint8_t buss_y_size = 10;
    uint8_t buss_x_size = 7;
public:
    vector<vector<char> > _buss;
    _city_buss_type1();
    virtual void create_buss(game_road& tmp);
    virtual void add_buss_to_road(game_road& tmp, int tmp_spawn_cord_x);
};

inline _city_buss_type1::_city_buss_type1()
{
    for (uint8_t i = 0; i < buss_y_size; ++i)
    {
        std::vector<char> temp;
        for (uint8_t j = 0; j < buss_x_size; ++j)
            temp.push_back(' ');
        _buss.push_back(temp);
        
    }

}

inline void _city_buss_type1::create_buss(game_road& tmp_road)
{
    for (uint8_t i = 0; i < buss_y_size; ++i)
    {
        for (uint8_t j = 0; j < buss_x_size; ++j)
        {
            _buss[i][j] = 219;
        }
    }
}

inline void _city_buss_type1::add_buss_to_road(game_road& tmp_road, int tmp_spawn_cord_x)
{
    for (uint8_t i = 0, y = spawn_cord_y; i < buss_y_size; ++i, ++y)
    {
        for (uint8_t j = 0, x = tmp_spawn_cord_x; j < buss_x_size; ++j, ++x)
        {
            tmp_road._road[y][x] = _buss[i][j];
        }
    }
}