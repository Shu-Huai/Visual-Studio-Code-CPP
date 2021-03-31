#include "ChildSiblingTree.h"
int main()
{
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int parents[] = {-1, 0, 0, 0, 0, 1, 1, 3, 5, 8};
    int n = 10;
    ChildSiblingTree<char> CST(c, parents, n);
    cout << "Degree: " << CST.GetDegree() << endl;
    cout << "Height: " << CST.GetHeight() << endl;
    cout << "Number: " << CST.GetNodeNumber() << endl;
    return 0;
}