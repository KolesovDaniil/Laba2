#include <table.h>
#include <Cell.h>
#include "iostream"
using namespace std;
int main()
{
    Cell cell{65};
    Cell cell_copy(cell);
    cout << cell_copy.get_num() << endl;
//    Table x(1,1);
//    cout << 1;
//    cout << x.get_ncell(0,0);
//    x.set_scell(0,0,"123");
//    cout << 1;
//    x.set_ncell(0,0,3.0);
//    x.set_scell(0,0,"123");
//    cout << 1;
//    std::cout << x.get_ncell(0,0) << std::endl;
//    int n = 3;

//    size_t c = size_t(n);

//    std::vector<std::vector<Cell> > matrix(n, std::vector<Cell>(n));

//    matrix[n][n] = 3;
//    cout << matrix.size() << endl << matrix[0].size()<<endl;
//    cout << matrix[0][0];
    return 0;
}
