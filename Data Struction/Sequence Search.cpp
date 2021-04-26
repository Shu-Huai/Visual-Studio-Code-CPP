#include "Assistance.h"
template <class ElemType>
int SequenceSearch(ElemType *elems, int length, ElemType key)
{
    int i = length;
    while (i >= 0 && elems[i] != key)
    {
        i--;
    }
    if (i)
    {
        return i - 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int elems[] = {-1, 64, 20, 33, 51, 70, 38};
    cout << "The resource is: " << endl;
    for (int i = 1; i < 7; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "Please input the number: ";
    int input = 0;
    cin >> input;
    elems[0] = input;
    cout << "The result is: " << SequenceSearch(elems, 6, input) << endl;
    return 0;
}