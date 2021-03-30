#include "UnionFindSets.h"
int main()
{
    const int n = 10;
    char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int a[] = {'a', 'g', 'i', 'c', 'a', 'h', 'f', 'f'};
    int b[] = {'b', 'd', 'j', 'b', 'c', 'i', 'e', 'd'};
    UnionFindSets<char> e(c, n);
    int i;
    for (i = 0; i < 8; i++)
    {
        e.OptimizedUnion(a[i], b[i]);
    }
    bool out[n];
    for (i = 0; i < n; i++)
        out[i] = false;
    int p = 0;
    while (p < n)
    {
        cout << "{" << e.GetElem(p);
        out[p] = true;
        for (i = p + 1; i < n; i++)
        {
            if (!e.Differ(e.GetElem(p), e.GetElem(i)))
            {
                cout << "," << e.GetElem(i);
                out[i] = true;
            }
        }
        cout << "}" << endl;
        while (p < n && out[p])
            p++;
    }

    return 0;
}