//
// Created by zeus on 04.10.2020.
//

#ifndef FINDE_PASS_LOOT_BOX_H
#define FINDE_PASS_LOOT_BOX_H


#include "Point.h"
#include <vector>
#include "Map.h"
#include <iostream>
#include <string>

using namespace std;



class Loot_box {
public:
    explicit Loot_box(Map *map, int loot_count);

    void Set_loot_c(vector<Point> l_c);

    void auto_gen_loot();

    vector<Point> Get_loot();

    void add_loot(Point l);

    bool is_it_in(Point a);
    void del_it(Point a);

    void save_coord();
    void Set_loot_count(int count);
    int Get_loot_count();
    string Get_saved();

private:
    vector<Point> loot_coord;
    string saved_coord;
    Map *map;
    int how_many_loot;

};


#endif //FINDE_PASS_LOOT_BOX_H
