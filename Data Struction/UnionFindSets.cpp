#include "UnionFindSets.h"
int main()
{
    const int n = 16;
    UnionFindSets<int> UFS(n);
    int c[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int a[n] = {1, 3, 3, 1, 3, 8, 1, 3, 3, 3, 3, 14, 16, 14, 1, 1};
    int b[n] = {2, 4, 5, 7, 6, 9, 8, 10, 11, 12, 13, 15, 0, 16, 3, 14};
    UFS = UnionFindSets<int>(c, n);
    for (int i = 0; i < n; i++)
    {
        UFS.SimpleUnion(a[i], b[i]);
    }
    cout << "Using SimpleUnion: " << endl
         << "Index:  ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl
         << "Parent: ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetParent(i);
    }
    cout << endl
         << "Data:   ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetElem(i);
    }
    cout << endl;
    UFS = UnionFindSets<int>(c, n);
    for (int i = 0; i < n; i++)
    {
        UFS.UnionByHeight(a[i], b[i]);
    }
    cout << "Using UnionByHeight: " << endl
         << "Index:  ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl
         << "Parent: ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetParent(i);
    }
    cout << endl
         << "Data:   ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetElem(i);
    }
    cout << endl;
    UFS = UnionFindSets<int>(c, n);
    for (int i = 0; i < n; i++)
    {
        UFS.UnionByNodeNumber(a[i], b[i]);
    }
    cout << "Using UnionByNodeNumber: " << endl
         << "Index:  ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl
         << "Parent: ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetParent(i);
    }
    cout << endl
         << "Data:   ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << UFS.GetElem(i);
    }
    cout << endl
         << "The UnionFindSets is ";
    bool out[n];
    for (int i = 0; i < n; i++)
    {
        out[i] = false;
    }
    int p = 0;
    while (p < n)
    {
        cout << "{" << UFS.GetElem(p);
        out[p] = true;
        for (int i = p + 1; i < n; i++)
        {
            if (!UFS.Differ(UFS.GetElem(p), UFS.GetElem(i)))
            {
                cout << ", " << UFS.GetElem(i);
                out[i] = true;
            }
        }
        cout << "}" << endl;
        while (p < n and out[p])
        {
            p++;
        }
    }
    return 0;
}