//
// Created by zeus on 04.10.2020.
//

#include <algorithm>
#include <utility>
#include "../headers/Map.h"

#include <stdlib.h>

Map::Map(string *n_map)
{
    this->s_map = n_map;
    this->high = count(begin(*n_map), end(*n_map), '\n');
    converter();
}

bool Map::if_it_here(Point a, char wh)
{
    if(check_size(a))
        return (map[a.y][a.x] == wh);
    return false;
}
void Map::converter()
{
    int j;

    j = 0;
    map.resize(1);

    for (char &i : *s_map)
    {
        if(i == '\n')
        {
            map[j].push_back('\0');
            j+=1;
            map.resize(j + 1);
        }
        else
            map[j].push_back(i);
    }
    s_map = nullptr;
    delete s_map;
}

void Map::uptd_map(Point new_p, char wh)
{
    if(check_size(new_p))
    {
        map[new_p.y][new_p.x] = wh;
    }
}
vector<string> Map::Get_map()
{
    return map;
}

bool Map::check_size(Point a)
{
    return a.y < high && map[a.y].length() > a.x;
}
int Map::Get_high()
{
    return high;
}

int Map::Get_len(int y)
{
    if(y < high)
        return map[y].length();
    return 0;
}


