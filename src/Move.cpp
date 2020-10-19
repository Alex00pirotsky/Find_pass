//
// Created by zeus on 05.10.2020.
//

#include <zconf.h>
#include <algorithm>
#include "../headers/Move.h"


Move::Move(Map *n_map, Player *n_plyr, Loot_box *n_loot)
{
    this->map = n_map;
    this->plyr = n_plyr;
    this->loot = n_loot;

}
void Move::start_walking()
{
    int i = 0;
    string great;
    great.push_back('+');
    great.push_back('a');
    great.push_back('b');

    while (1)
    {

        if(loot->is_it_in(plyr->Get_plyer_pos()))
        {
            loot->del_it(plyr->Get_plyer_pos());
            if(loot->Get_loot_count() <= 0) // TODO think about it
                break;
        }
        if(map->if_it_here(where_go(great[i], great[great.length() - 1]), great[i]))
        {
            make_step(plyr->Get_plyer_pos(), great[i+1],where_go(great[i],great[great.length() - 1]));
            i = -1;
            if(check_fin())
                break;
        }
        i++;
        if(i >= great.length() - 2)
        {
            great.push_back('b' + i);
            i = 0;
        }
    }
}
Point Move::where_go(char wh, char exept)
{
    Point road_tmp;

    for(auto all_step : all_steps)
    {
        road_tmp.x = plyr->Get_plyer_pos().x + all_step.x;
        road_tmp.y = plyr->Get_plyer_pos().y + all_step.y;
        if(map->check_size(road_tmp))
        {
            if(!map->if_it_here(road_tmp, ' ') && !map->if_it_here(road_tmp, exept))
            {
                if(map->if_it_here(road_tmp, wh))
                    return road_tmp;
            }
        }
    }
    return plyr->Get_plyer_pos();
}

bool Move::check_fin()
{
    bool res;
    res = true;
    for(auto m : map->Get_map())
    {
        if(count(begin(m), end(m), '+'))
            res = false;
    }
    return res;
}

void Move::make_step(Point pr_pos, char change, Point n_pos)
{
    main_road.push_back(pr_pos);
    map->uptd_map(pr_pos, change);
    plyr->Set_plyr(n_pos);
    map->uptd_map(n_pos, '@');
}

void Move::save_road()
{
    road = "ALL ROAD\n";
    for(auto & i : main_road)
    {
        road += "X = ";
        road += to_string(i.x);
        road += " Y = ";
        road += to_string(i.x);
        road += "\n";
    }
}
string Move::Get_road()
{
    return road;
}
