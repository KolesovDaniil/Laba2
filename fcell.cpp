#include "fcell.h"
#include "sstream"


FCell::FCell(std::string _f_string){
    std::istringstream is(_f_string);
    is.ignore();
    is >> cmd.operation;
    is >> cmd.fc_coords.first;
    is >> cmd.fc_coords.second;
    is >> cmd.sc_coords.first;
    is >> cmd.sc_coords.second;
}
void FCell::set(std::string _f_string){
    std::istringstream is(_f_string);
    is.ignore();
    is >> cmd.operation;
    is >> cmd.fc_coords.first;
    is >> cmd.fc_coords.second;
    is >> cmd.sc_coords.first;
    is >> cmd.sc_coords.second;
}
