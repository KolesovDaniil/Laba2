#include <table.h>
#include <Cell.h>
#include "iostream"
using namespace std;
int main()
{
    Table table{3,3};
    table.set_ncell(0,0,54);
    cout << "1: " << table.get_ncell(0,0) << endl;
    cout << "2: " << table.get_ncell(2,2) << endl;
    try {
        cout << "3: " << table.get_scell(1000,1000) << endl;
    } catch (const char* str) {
        cout << str << endl;
    }
    try {
        table.set_ncell(6,6,56);
    } catch (const char* str) {
        cout << "4: " <<str << endl;
    }

    vector<int> vec = {1,2,3,4,5};
    cout << vec[0] << endl;
    return 0;
}
