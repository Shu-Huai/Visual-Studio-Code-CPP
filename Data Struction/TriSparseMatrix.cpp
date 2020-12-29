#include "TriSparseMatrix.h"
using namespace std;
int main()
{
    TriSparseMatrix<int> t1(50, 50, 100);
    t1.SetElem(1, 2, 50);
    int temp = 0;
    t1.GetElem(1, 2, temp);
    cout << temp << endl;
    TriSparseMatrix<int> t2(50, 50, 100);
    t1.SimpleTranspose(t1, t2);
    t1.GetElem(2, 1, temp);
    cout << temp << endl;
    return 0;
}