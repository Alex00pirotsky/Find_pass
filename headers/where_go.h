//
// Created by zeus on 05.10.2020.
//

#ifndef FINDE_PASS_WHERE_GO_H
#define FINDE_PASS_WHERE_GO_H

#include <vector>
#include "Point.h"

std::vector<Point> const all_steps =
        {
                {0,-1}, // "N"
                {1,0}, // W
                {0,1}, // S
                {-1,0} // E
        };

#endif //FINDE_PASS_WHERE_GO_H
