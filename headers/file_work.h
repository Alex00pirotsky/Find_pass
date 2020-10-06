//
// Created by zeus on 04.10.2020.
//

#ifndef FINDE_PASS_FILE_WORK_H
#define FINDE_PASS_FILE_WORK_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class file_work {
public:
    file_work(const string& path_map, const string& path_data);

    void Set_path_to_map(string n_path);
    void Set_path_store_data(string n_path);
    static string Get_data(const string& path);

    static void put_data(const string& data, const string& path);

private:

    string path_to_map;
    string path_store_data;

};


#endif //FINDE_PASS_FILE_WORK_H
