#include "Cell.h"

#include <iostream>

void Cell::set(std::string i_string_value){

        set_numeric_value = false;
        set_string_value = true;
        string_value = i_string_value;

}

void Cell::set(double i_numeric_value){

        set_string_value = false;
        set_numeric_value = true;
        numeric_value = i_numeric_value;

}

double Cell::get_num(){
    if (!set_string_value&&!set_numeric_value){
        return NULL;
    }
    else if(!set_string_value){
         return numeric_value;
    }
    else{
        throw "Type error";
    }
}

std::string Cell::get_str(){
    if (!set_string_value&&!set_numeric_value){
        return "";
    }
    else if(!set_numeric_value){
         return string_value;
    }
    else throw "Type error";
}

void Cell::clear(){
    numeric_value = NULL;
    string_value = "";
    set_string_value = false;
    set_numeric_value = false;
}


char Cell::type(){
    if (set_string_value) return 's';
    else if(set_numeric_value) return 'n';
            else return 'e';

}
