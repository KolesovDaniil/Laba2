#pragma once
#include "My_Vector.h"
#include "cell.h"
#include "scell.h"
#include "ncell.h"
#include "fcell.h"
#include "ecell.h"
#include "fstream"


class Table
{
private:
//    int rows, columns;
    My_Vector<My_Vector<Cell*>> matrix;
    void create_fcell(int,int,std::string);
    void create_ncell(int,int,std::string);
    void create_scell(int,int,std::string);
    void create_ecell(int,int);
    std::string get_scell(int,int);
    double get_ncell(int,int);
    Command get_fcell(int,int);
public:
    My_Vector<My_Vector<Cell*>> get_matrix() {return matrix;}
    friend std::ofstream& operator<<(std::ofstream& os, Table& table){
        os << table.size().first << "," << table.size().second << ",";
        for(size_t i = 0; i!=table.size().first; ++i){
            for(size_t j = 0; j!=table.size().second; ++j){
                os << table.get_cell(i,j)<< ':' << table.type_check(i,j) << ",";
            }
        }
        return os;
    }
    Table(): matrix(0, My_Vector<Cell*>(0)){}
    Table(int _rows, int _columns): matrix(_rows, My_Vector<Cell*>(_columns, new ECell())){}
    Table(Table&);
    ~Table(){}
    void operator=(Table& _table){this->matrix = _table.get_matrix();}
    std::string get_cell (int,int);
    void create_cell(int,int,char,std::string);
    void update_cell(int,int,char,std::string);
    void clear_all();
    void clear_cell(int,int);
    std::string process(int,int);
    std::pair<int,int> size(){return std::pair<int,int>(matrix.size(),matrix[0].size());}
    void resize(int,int);
    char type_check(int row, int column) {return matrix[row][column]->type_check();}
    void read_file(std::string);
    void write_file(std::string);


};

