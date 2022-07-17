#pragma once
#include <iostream>
#include <vector>
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
    vector<vector<char>> _map;
    game_map()
    {
        for (size_t i = 0; i < map_y_size; ++i)
        {
            std::vector<char> temp;
            for (size_t j = 0; j < map_x_size; ++j)
                temp.push_back(rand() % 666);
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
    ~game_map() = default;
};

class game_road
{
public:
    uint8_t spawn_cord_x = 10;
    uint8_t spawn_cord_y = 2;
public:
    vector<vector<char>> _road;
    game_road()
    {
        for (size_t i = 0; i < road_y_size; ++i)
        {
            std::vector<char> temp;
            for (size_t j = 0; j < road_x_size; ++j)
                temp.push_back(rand() % 666);
            _road.push_back(temp);
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
    }
};
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
