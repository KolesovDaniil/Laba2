#pragma once
#include "cell.h"
#include "iostream"


class ECell: public Cell
{
private:
    std::string str;
public:
    ECell(): str("") {}
    ECell(ECell& _ecell){str = "";}
    ~ECell() {}
    virtual char type_check() override {return 'e';}
};
