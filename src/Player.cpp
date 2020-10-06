//
// Created by zeus on 04.10.2020.
//

#include "../headers/Player.h"

Player::Player(Map *n_map)
{
    this->map = n_map;
}

void Player::Set_plyr(Point p)
{
    this->plyr = p;
}

Point Player::Get_plyer_pos()
{
    return plyr;
}

void Player::auto_spawn_plyr()
{
    Point x_y;

    while (1)
    {
        x_y.y = rand() % map->Get_high() - 1;
        if (x_y.y  >= 0)
            x_y.x = rand() % map->Get_len(x_y.y) - 1;
        else
            continue;
        if(map->if_it_here(x_y, '+'))
        {
            Set_plyr(x_y);
            break;
        }
    }
}

Point Player::Get_start_p()
{
    return start_pos;
}

void Player::save_coord()
{
    saved_coord = "Player first pos\n";
    saved_coord += "X = ";
    saved_coord += to_string(plyr.x);
    saved_coord += "Y = ";
    saved_coord += to_string(plyr.y);
}

string Player::Get_saved()
{
    return saved_coord;
}