#pragma once
#include "cell.h"
#include "iostream"


class NCell: public Cell
{
private:
    double number;
public:
    NCell(): number(0) {}
    NCell(double _number): number(_number){}
    NCell(NCell& _ncell): number(_ncell.get()){}
    ~NCell() override {}
    virtual char type_check() override {return 'n';}
    double get() const {return number;}
    void set(double _number) {number=_number;}
};
