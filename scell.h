#pragma once
#include "cell.h"
#include "iostream"
#include "QString"


class SCell: public Cell
{
private:
    std::string str;
public:
    SCell(): str("") {}
    SCell(std::string _str): str(_str) {}
    SCell(SCell& _scell): str(_scell.get()){}
    ~SCell(){}
    virtual char type_check() override {return 's';}
    std::string get() const {return str;}
    void set(std::string _str) {str=_str;}
};
