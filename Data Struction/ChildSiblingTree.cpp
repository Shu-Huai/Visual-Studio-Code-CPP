#include "ChildSiblingTree.h"
int main()
{
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int parents[] = {-1, 0, 0, 0, 0, 1, 1, 3, 5, 8};
    int n = 10;
    ChildSiblingTree<char> t(c, parents, n);
    //        A
    //   B    C    D   E
    // F  G      H
    //          I
    //        J
    cout << "树的度为：" << t.GetDegree() << endl;
    cout << "树的高度为：" << t.GetHeight() << endl;
    return 0;
}