#pragma once
#include <iostream>


class Cell{
private:
    std::string string_value;
    double numeric_value;
    bool set_string_value, set_numeric_value;\

public:
    void set(std::string);
    void set(double);

    double get_num();
    std::string get_str();

    char type();

    void clear();

    Cell()
        : string_value{""},
          numeric_value{NULL},
          set_string_value{false},
          set_numeric_value{false}{}

    Cell(const std::string i_string_value)
        : string_value{i_string_value},
          numeric_value{NULL},
          set_string_value{true},
          set_numeric_value{false}{}

    Cell(const double i_numeric_value)
        : string_value{""},
          numeric_value{i_numeric_value},
          set_string_value{false},
          set_numeric_value{true}{}

    Cell(const Cell& cell)
        : string_value{cell.string_value},
          numeric_value{cell.numeric_value},
          set_string_value{cell.set_string_value},
          set_numeric_value{cell.set_numeric_value}{}
};


