#include <iostream>
#include <fstream>
#include "../headers/file_work.h"
#include "../headers/Map.h"
#include <algorithm>

#include "../headers/Loot_box.h"

#include "../headers/Player.h"
#include "../headers/Move.h"

using namespace std;


void start_point(const string& path_map, const string& path_data, int count)
{
    file_work *work = new file_work(path_map , path_data);

    string tmp = work->Get_data(path_map);
    Map *map = new Map(&tmp);

    Loot_box *loot = new Loot_box(map, count);
    Player *plyr = new Player(map);

    plyr->auto_spawn_plyr();
    loot->auto_gen_loot();

    loot->save_coord();
    plyr->save_coord();

    map->uptd_map(plyr->Get_plyer_pos() , '@');

    Move *move  = new Move(map, plyr,loot);

    move->start_walking();
    move->save_road();

    tmp = plyr->Get_saved();
    tmp += "\n\n\n";
    tmp += loot->Get_saved();
    tmp += "\n\n\n";
    tmp += move->Get_road();
    tmp += "\n\n\n";
    work->put_data(tmp, path_data);


}
int main(int argc , char **argv)
{
    if(argc == 4)
    {
        int count = atoi(argv[3]);
        if(count < 10)
            start_point(argv[1], argv[2], count);
        else
            cout << "loot should be < 10" << endl;
    }
    else
    {
        cout << argc << endl;
        cout << "IT should be 3 arg" << endl;
    }

    return 0;
}
