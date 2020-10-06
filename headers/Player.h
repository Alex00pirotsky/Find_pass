//
// Created by zeus on 04.10.2020.
//

#ifndef FINDE_PASS_PLAYER_H
#define FINDE_PASS_PLAYER_H

#include "Map.h"
#include "Point.h"


class Player {
public:
    explicit Player(Map *map);

    void Set_plyr(Point p);

    Point Get_plyer_pos();

    Point Get_start_p();


    void auto_spawn_plyr();

    void save_coord();

    string Get_saved();

private:
    Point plyr;
    Point start_pos;
    Map *map;
    string saved_coord;

};


#endif //FINDE_PASS_PLAYER_H
