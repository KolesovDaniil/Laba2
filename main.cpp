#include "mainwindow.h"
#include <table.h>
#include <assert.h>

#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    Table table(3,3);
    assert(table.size().first==3);
    assert(table.size().second==3);
    table.update_cell(0,0,'s',"hello");
    assert(table.get_cell(0,0)=="hello");
    table.update_cell(0,0,'n',"2");
    assert(table.get_cell(0,0)=="2");
    table.update_cell(0,1,'n',"2");
    table.update_cell(0,2,'f',"=SUM 0 0 0 1");
    assert(table.process(0,2) == "4.000000");
    table.update_cell(0,2,'f',"=MUL 0 0 0 1");
    assert(table.process(0,2) == "4.000000");
    table.update_cell(0,2,'f',"=AVG 0 0 0 1");
    assert(table.process(0,2) == "2.000000");
    table.update_cell(0,0,'s',"hello");
    assert(table.process(0,2) == "Not only num cells");
    table.update_cell(0,2,'f',"AVG 0 0 0 1");
    assert(table.process(0,2) == "Error");
    table.clear_cell(0,0);
    assert(table.type_check(0,0)=='e');
    for(int i=0; i<table.size().first;++i){
        for(int j=0; j<table.size().second; ++j){
            table.update_cell(i,j,'n',(std::to_string(i*j)));
        }
    }
    for(int i=0; i<table.size().first;++i){
        for(int j=0; j<table.size().second; ++j){
            assert(table.type_check(i,j)=='n');
        }
    }
    table.clear_all();
    for(int i=0; i<table.size().first;++i){
        for(int j=0; j<table.size().second; ++j){
            assert(table.type_check(i,j)=='e');
        }
    }
    table.create_cell(2,2,'s',"everything is good");
    assert(table.type_check(2,2)=='s');
    assert(table.get_cell(2,2)=="everything is good");
    for(int i=0; i<table.size().first;++i){
        for(int j=0; j<table.size().second; ++j){
            table.update_cell(i,j,'n',(std::to_string(i*j)));
        }
    }
    table.write_file("test.txt");
    table.read_file("test.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
