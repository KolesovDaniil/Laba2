#pragma once
#include <vector>
#include "Cell.h"
#include "iostream"

class Table
{
public:

    Table():matrix{0, std::vector<Cell>(0)}{}
    Table(size_t rows, size_t columns):matrix{rows, std::vector<Cell>(columns)}{}
    Table(Table&);
    ~Table();

    void clear_table();

    double sum(std::size_t  column_number);
    double mean(std::size_t  column_number);

    void set_scell(std::size_t row, std::size_t column, std::string);
    void set_ncell(std::size_t row, std::size_t column, double numeric_value);
    char type_check(std::size_t , std::size_t);
    std::pair<int, int> size();
    std::string get_scell(std::size_t row, std::size_t column);
    double get_ncell(std::size_t row, std::size_t column);

private:
    void size_check(size_t,size_t);
    std::vector <std::vector<Cell>> matrix;

};
