#include "Binary Sort Tree.h"
#include "Assistance.h"
int main()
{
    BinarySortTree<int> BST;
    int elems[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        BST.InsertElem(elems[i]);
    }
    char functionSelect = 0;
    int elem = 0;
    int key = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Insert an element.";
        cout << endl
             << "2. Find an element.";
        cout << endl
             << "3. Delete an element.";
        cout << endl
             << "4. Pre order Traverse.";
        cout << endl
             << "5. In Order Traverse.";
        cout << endl
             << "6. Post Order Traverse.";
        cout << endl
             << "7. If it is a binary sort tree.";
        cout << endl
             << "8. Output elements bigger than the key.";
        cout << endl
             << "9. Find and insert.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select function(0~9): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << endl
                 << "Please input the element: ";
            cin >> elem;
            try
            {
                BST.InsertElem(elem);
            }
            catch (string &error)
            {
                cout << error << endl;
            }
            break;
        case '2':
            cout << endl
                 << "Please input the element: ";
            cin >> elem;
            if (!BST.Find(elem))
            {
                cout << endl
                     << "Element does not exsit.";
            }
            else
            {
                cout << endl
                     << "Element exsits.";
            }
            break;
        case '3':
            cout << endl
                 << "Please input the element: ";
            cin >> elem;
            try
            {
                BST.DeleteElem(elem);
            }
            catch (string &error)
            {
                cout << error << endl;
            }
            break;
        case '4':
            cout << endl;
            BST.PreOrderTraverse();
            break;
        case '5':
            cout << endl;
            BST.InOrderTraverse();
            break;
        case '6':
            cout << endl;
            BST.PostOrderTraverse();
            break;
        case '7':
            cout << endl
                 << "This tree " << (BST.IsBinarySortTree() ? "is" : "is not") << " a binary sort tree.";
            break;
        case '8':
            cout << endl
                 << "Please input the ley: ";
            cin >> key;
            BST.GetElemsAbove(key);
            break;
        case '9':
            cout << endl
                 << "Please input the element: ";
            cin >> elem;
            BST.FindAndInsert(elem);
            break;
        }
    }
    return 0;
}