#pragma once
#include "cell.h"
#include "iostream"

class Command{
public:
    std::string operation;
    std::pair<int,int> fc_coords;
    std::pair<int,int> sc_coords;
    Command(): operation(""), fc_coords(std::pair<int,int>(-1,-1)), sc_coords(std::pair<int,int>(-1,-1)){}
};

class FCell: public Cell
{
private:
    Command cmd;
public:
    FCell(): cmd(){}
    FCell(std::string _f_string); //написать реализацию когда f_string сразу раскладывается на операцию и диапазон
    FCell(FCell& _fcell){this->cmd = _fcell.get();}
    ~FCell() override {}
    void set(std::string);
    Command get() const {return cmd;}
    virtual char type_check() override {return 'f';}
};

