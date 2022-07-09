#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <random>

using namespace std;
random_device Rand;

const int Map_y_size = 30;
const int Map_x_size = 50;

class game_map
{
public:
    char** map = new char* [Map_y_size] {};
    game_map()
    {
        for (int i = 0; i < Map_y_size; ++i)
        {
            map[i] = new char[Map_x_size];
        }

        for (int i = 0; i < Map_y_size; ++i)
        {
            for (int j = 0; j < Map_x_size; ++j)
            {
                if (i == 0 || i == Map_y_size - 1)
                    map[i][j] = '.';
                else if (j == 30 && i <= 15)
                    map[i][j] = '.';
                else if (j >= 30 && i == 15)
                    map[i][j] = '.';
                else
                {
                    map[i][j] = ' ';
                    map[i][0] = '.';
                    map[i][Map_x_size - 1] = '.';
                }
            }
        }
    }
};

void game_map_draw(game_map& tmp)
{
    for (int i = 0; i < Map_y_size; ++i)
    {
        for (int j = 0; j < Map_x_size; ++j)
        {
            cout << tmp.map[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    game_map test;
    game_map_draw(test);

    system("pause");
    return 0;
}
