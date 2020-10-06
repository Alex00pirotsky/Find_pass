//
// Created by zeus on 04.10.2020.
//

#include "../headers/Loot_box.h"
#include <algorithm>
#include <utility>


Loot_box::Loot_box(Map *n_map, int loot_count)
{
    this->map = n_map;
    this->how_many_loot = loot_count;

}

void Loot_box::Set_loot_c(vector<Point> l_c)
{
    this->loot_coord  = std::move(l_c);
}

void Loot_box::auto_gen_loot()
{
    Point x_y;
    int n;
    loot_coord.clear();
    n = how_many_loot;

    while (n > 0)
    {
        x_y.y = rand() % map->Get_high() - 1;
        if (x_y.y  >= 0)
            x_y.x = rand() % map->Get_len(x_y.y) - 1;
        else
            continue;
        if(map->if_it_here(x_y, '+') && !is_it_in(x_y))
        {
            loot_coord.push_back(x_y);
            n--;
        }
    }
}

void Loot_box::save_coord()
{
    saved_coord = "Looot coordinate\n";
    for (auto & i : loot_coord)
    {
        saved_coord += "X = ";
        saved_coord += to_string(i.x);
        saved_coord += " Y = ";
        saved_coord += to_string(i.y);
        saved_coord += '\n';
    }
}

vector<Point> Loot_box::Get_loot()
{
    return loot_coord;
}

void Loot_box::add_loot(Point l)
{
    loot_coord.push_back(l);
}


bool Loot_box::is_it_in(Point a)
{
    for(auto &i : loot_coord)
    {
        if(i.x == a.x && i.y == a.y)
            return true;
    }
    return false;
}

void Loot_box::del_it(Point a)
{
    for(int i = 0; i < loot_coord.size(); i++)
    {
        if(loot_coord[i].x == a.x && loot_coord[i].y == a.y)
        {
            loot_coord.erase(loot_coord.begin() + i);
            break;
        }
    }
    this->how_many_loot -= 1;
}

void Loot_box::Set_loot_count(int count)
{
    this->how_many_loot = count;
}
int Loot_box::Get_loot_count()
{
    return how_many_loot;
}

string Loot_box::Get_saved()
{
    return saved_coord;
}
