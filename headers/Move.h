//
// Created by zeus on 05.10.2020.
//

#ifndef FINDE_PASS_MOVE_H
#define FINDE_PASS_MOVE_H

#include "Map.h"
#include "Player.h"
#include "Loot_box.h"
#include "where_go.h"
#include <vector>
#include <string>


class Move {
public:
    Move(Map *n_map, Player *n_plyr, Loot_box *n_loot);


    void start_walking();
    void save_road();
    string Get_road();

private:


    Point where_go(char wh, char exept);
    bool check_fin();
    void make_step(Point pr_pos, char change, Point n_pos);

    vector<Point> main_road;

    string road;

    Map *map;
    Player *plyr;
    Loot_box *loot;
};


#endif //FINDE_PASS_MOVE_H
