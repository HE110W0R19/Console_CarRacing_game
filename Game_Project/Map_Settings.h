#pragma once
#include <iostream>
#include <vector>
#include <random>

using namespace std;

//game map sizes
const uint8_t map_y_size = 45;
const uint8_t map_x_size = 170;

const uint8_t road_y_size = 55;
const uint8_t road_x_size = 101;
uint8_t road_y_spawn_cord = 41;

class game_map
{
public:
    vector<vector<char>> _map;
    game_map();
    ~game_map() = default;
};

game_map::game_map()
{
    for (size_t i = 0; i < map_y_size; ++i)
    {
        std::vector<char> temp;
        for (size_t j = 0; j < map_x_size; ++j)
            temp.push_back(' ');
        _map.push_back(temp);
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

class game_road
{
public:
    uint8_t spawn_cord_x = 10;
    uint8_t spawn_cord_y = 2;
public:
    vector<vector<char>> _road;
    game_road();
    void create_road();
    void add_road_to_map(game_map& tmp_map);
    void road_animation();
};

game_road::game_road()
{
    for (uint8_t i = 0; i < road_y_size; ++i)
    {
        std::vector<char> temp;
        for (uint8_t j = 0; j < road_x_size; ++j)
            temp.push_back(' ');
        _road.push_back(temp);
    }
}

inline void game_road::road_animation()
{
    //road animation
    for (uint8_t i = 0; i < road_x_size; i++)
    {
        char t = this->_road[road_y_size - 2][i];
        uint8_t j = 0;
        for (j = road_y_size - 1; j > 0; --j)
        {
            this->_road[j][i] = this->_road[j - 1][i];
        }
        this->_road[j][i] = t;
    }
}

inline void game_road::add_road_to_map(game_map& tmp_map)
{
    for (uint8_t i = 0, y = spawn_cord_y; i < road_y_spawn_cord; ++i, ++y)
    {
        for (uint8_t j = 0, x = spawn_cord_x; j < road_x_size; ++j, ++x)
        {
            tmp_map._map[y][x] = _road[i][j];
        }
    }
}

void game_road::create_road()
{
    for (uint8_t i = 0; i < road_y_size; ++i)
    {
        for (uint8_t j = 0; j < road_x_size; ++j)
        {
            /////add lines
            if (j == 0 || j == road_x_size - 1 || j == 49 || j == 50)
                _road[i][j] = 221;
            /////add left chipper
            else if (j == 7 && i % 2 != 0)
                _road[i][j] = 185;
            else if (j == 6 && i % 2 != 0)
                _road[i][j] = 201;
            ////add right chipper
            else if (j == 94 && i % 2 != 0)
                _road[i][j] = 204;
            else if (j == 95 && i % 2 != 0)
                _road[i][j] = 187;
            /////////////////////////
            else if ((j == 94 || j == 7) && i % 2 == 0)
                _road[i][j] = 186;//adding center fender for left and right fender
            else if (j % 10 == 0 && i % 2 == 0)
                _road[i][j] = 254;//add dividing lines
            else
                _road[i][j] = ' ';
        }
    }
}
//
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
