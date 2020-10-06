//
// Created by zeus on 04.10.2020.
//

#ifndef FINDE_PASS_MAP_H
#define FINDE_PASS_MAP_H

#include <string>
#include <vector>
#include <iostream>

#include "Point.h"

using namespace std;

class Map {
public:
    explicit Map(string *n_map);

    bool if_it_here(Point a, char wh);
    void uptd_map(Point new_p, char wh);
    vector<string> Get_map();
    int Get_high();
    int Get_len(int y);

    bool check_size(Point a);



private:
    void converter();

    int width;
    int high;

    string *s_map;
    vector<string> map;




};


#endif //FINDE_PASS_MAP_H
