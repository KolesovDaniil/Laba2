#include "table.h"

using namespace std;


void Table::size_check(size_t row, size_t column){
    if(row > matrix.size() || column > matrix[0].size()) throw "Out_of_range";
}

string Table::get_scell(size_t row, size_t column){
    try {
        size_check(row,column);
        return matrix[row][column].get_str();
    } catch (string str) {
        cout << str << endl;
    }
    return "hello";
}
double Table::get_ncell(size_t row, size_t column){
    try {
        size_check(row,column);
        return matrix[row][column].get_num();
    } catch (...) {
        cout << "String type" << endl;
    }
    return 1.1;
}

void Table::set_scell(size_t row, size_t column, string str){
    try {
        size_check(row,column);
    } catch (string str) {
        cout << str << endl;
    }
    matrix[row][column].set(str);
}

void Table::set_ncell(size_t row, size_t column, double num){
    try {
        size_check(row,column);
    } catch (string str) {
        cout << str << endl;
    }
    matrix[row][column].set(num);
}

pair<int, int> Table::size(){
     pair<int, int> table_size(matrix.size(),matrix[0].size());
     return table_size;
}


char Table::type_check(size_t  row, size_t  column){
    if(matrix[row][column].type()=='s'){
        return 's';
    }
    else if(matrix[row][column].type()=='n'){
        return 'n';
    }
    else{
        return 'e';
    }
}

Table::Table(Table& table){
    vector <vector<Cell>> matrix(size_t(table.size().first), vector<Cell>(size_t(table.size().second)));
        for(size_t i=0; i<size_t(table.size().first); i++){
            for(size_t j=0; j<size_t(table.size().second); j++){
                if(table.type_check(i,j)=='s'){
                    matrix[i][j].set(table.get_scell(i,j));
                }
                if(table.type_check(i,j)=='n'){
                    matrix[i][j].set(table.get_ncell(i,j));
                }
                if(table.type_check(i,j)=='e'){
                    matrix[i][j].clear();
                }
            }
        }
}
Table::~Table(){
    matrix.clear();
}

void Table::clear_table(){
    for(size_t i=0; i<matrix.size(); i++){
        for(size_t j=0; j<matrix[0].size(); j++){
            matrix[i][j].clear();
        }
    }
}

double Table::sum(size_t  column_number){
    double sum = 0;
    for(size_t  j=0; j<matrix.size(); j++){
        try {
            sum += matrix[column_number][j].get_num();
        } catch (std::string str) {
            std::cout<<str<<std::endl;
        }
    }
    return sum;
}

double Table::mean(std::size_t  column_number){
    double sum = 0;
    for(size_t  j=0; j<matrix.size(); j++){
        try {
            sum += matrix[column_number][j].get_num();
        } catch (std::string str) {
            std::cout<<str<<std::endl;
        }
    }
    return sum/double(matrix[column_number].size());
}
