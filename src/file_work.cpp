//
// Created by zeus on 04.10.2020.
//

//#include "file_work.h"
#include "../headers/file_work.h"

#include <utility>

file_work::file_work(const string& path_map, const string& path_data)
{
    this->path_to_map = path_map;
    this->path_store_data = path_data;
}

string file_work::Get_data(const string& path)
{
    string data;
    char buf;
    ifstream fin(path);

    if (!fin.is_open())
    {
        cout << "Файл не может быть открыт!\n";
        exit(1);
    }
    else
    {
        while (!fin.eof())
        {
            buf = fin.get();
            data.push_back(buf);
        }
    }
    fin.close();
    data[data.length() - 1] = '\0';
    return data;
}

void file_work::put_data(string const& data,const string& path)
{
    ofstream fout(path);
    if(fout.is_open())
    {
        fout << data;
        fout.close();
    }
    else
    {
        cout << "Файл не может быть открыт!\n";
        exit(1);
    }
}

void file_work::Set_path_to_map(string n_path)
{
    this->path_to_map = std::move(n_path);

}

void file_work::Set_path_store_data(string n_path)
{
    this->path_store_data = std::move(n_path);
}


