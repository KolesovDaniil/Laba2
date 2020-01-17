#include "table.h"
#include <sstream>
#include <fstream>

Table::Table(Table& _table){
    for(int i=0;i<_table.size().first;++i){
        for(int j=0;j<_table.size().second;++j){
            this->matrix = _table.get_matrix();
        }
    }
}
void Table::create_ncell(int row , int column, std::string str){
    delete dynamic_cast<NCell*>(matrix[row][column]);
    matrix[row][column] = new NCell(std::stod(str));
}

void Table::create_scell(int row, int column, std::string str){
    delete dynamic_cast<SCell*>(matrix[row][column]);
    matrix[row][column] = new SCell(str);
}
void Table::create_fcell(int row, int column, std::string str){
    delete dynamic_cast<FCell*>(matrix[row][column]);
    matrix[row][column] = new FCell(str);
}

void Table::create_ecell(int row, int column){
//    delete dynamic_cast<ECell*>(matrix[row][column]);
    matrix[row][column] = new ECell();
}

double Table::get_ncell(int row, int column){
    return dynamic_cast<NCell*>(matrix[row][column])->get();
}

std::string Table::get_scell(int row, int column){
    return dynamic_cast<SCell*>(matrix[row][column])->get();
}

Command Table::get_fcell(int row, int column){
    return dynamic_cast<FCell*>(matrix[row][column])->get();
}
std::string Table::get_cell(int row, int column){
    char type = matrix[row][column]->type_check();
    switch (type) {
    case 'n':{
        std::ostringstream strs;
        strs << get_ncell(row,column);
        return strs.str();
    }
    case 's':
        return get_scell(row,column);
    case 'f':{
        Command cmd = get_fcell(row,column);
        std::ostringstream strs;
        strs << "=" <<cmd.operation << " " << cmd.fc_coords.first << " " << cmd.fc_coords.second << " " << cmd.sc_coords.first << " " << cmd.sc_coords.second;
        return strs.str();
    }
    case 'e':
        return "";
    }
}

void Table::clear_all(){
    for(int i=0; i < size().first; ++i){
        for(int j=0; j < size().second; ++j){
            create_ecell(i,j);
        }
    }
}

void Table::clear_cell(int row, int column){
    create_ecell(row,column);
}

void Table::create_cell(int row, int column, char _type, std::string str){
    switch(_type){
    case 'n':
        create_ncell(row,column,str);
        break;
    case 's':
        create_scell(row,column,str);
        break;
    case 'f':
        create_fcell(row,column,str);
        break;
    case 'e':
        create_ecell(row,column);
        break;
    }
}
void Table::update_cell(int row, int column, char _type, std::string str){
    char type=matrix[row][column]->type_check();
    switch(type){
    case 'n':
        if(type==_type){
            dynamic_cast<NCell*>(matrix[row][column])->set(std::stod(str));
        }
        else{
            create_cell(row,column,_type, str);
        }
        break;
    case 's':
        if(_type==type){
            dynamic_cast<SCell*>(matrix[row][column])->set(str);
        }
        else{
            create_cell(row,column,_type, str);
        }
        break;
    case 'f':
        if(_type==type){
            dynamic_cast<FCell*>(matrix[row][column])->set(str);
        }
        else{
            create_cell(row,column,_type, str);
        }
        break;
    case 'e':
        create_cell(row,column,_type, str);
        break;
    }
}

std::string Table::process(int row, int column){
    Command cmd = get_fcell(row, column);
    if(cmd.operation=="SUM"){
        double sum = 0;
        for(int i=cmd.fc_coords.first;i<=cmd.sc_coords.first;++i ){
            for(int j=cmd.fc_coords.second;j<=cmd.sc_coords.second;++j)
                if(matrix[i][j]->type_check()=='n'){
                    sum+=double(dynamic_cast<NCell*>(matrix[i][j])->get())  ;
                }
                else return "Not only num cells";
        }
        return std::to_string(sum);
    }
    else if(cmd.operation=="MUL"){
        double sum = 1;
        for(int i=cmd.fc_coords.first;i<=cmd.sc_coords.first;++i ){
            for(int j=cmd.fc_coords.second;j<=cmd.sc_coords.second;++j)
                if(matrix[i][j]->type_check()=='n'){
                    sum*=double(dynamic_cast<NCell*>(matrix[i][j])->get());
                }
            else return "Not only num cells";
        }
        return std::to_string(sum);
    }
    else if(cmd.operation=="AVG"){
        double sum = 0;
        int count = 0;
        for(int i=cmd.fc_coords.first;i<=cmd.sc_coords.first;++i ){
            for(int j=cmd.fc_coords.second;j<=cmd.sc_coords.second;++j)
                if(matrix[i][j]->type_check()=='n'){
                    sum+=double(dynamic_cast<NCell*>(matrix[i][j])->get());
                    count++;
                }
                else return "Not only num cells";
            }
        return std::to_string(sum/double(count));
    }else return "Error";
}
void Table::read_file(std::string file_name){
    std::ifstream in(file_name);
    std::string line;
    std::string data;
    std::string type;
    int rows, columns;
    if (in.is_open())
    {
        getline(in, line, ',');
        rows = std::stoi(line);
        getline(in, line, ',');
        columns = std::stoi(line);
        std::istringstream iss();
        this->resize(rows,columns);
        for(int i=0; i<this->size().first;++i){
            for(int j=0; j<this->size().second; ++j){
                getline(in, line, ',');
                std::istringstream iss(line);
                getline(iss, data, ':');
                getline(iss, type, ':');
                this->update_cell(i,j,type[0],data);
            }
        }
    }
    in.close();
}
void Table::write_file(std::string file_name){
    std::ofstream out(file_name);
    out << *this;
    out.close();
}
void Table::resize(int _rows, int _columns){
    My_Vector<My_Vector<Cell*> > tmp(_rows, My_Vector<Cell*>(_columns, new ECell()));
    matrix = tmp;
}
