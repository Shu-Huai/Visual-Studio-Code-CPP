#include "Link List.h"
int main()
{
    char functionSelect = 0;
    LinkList<int> list;
    LinkList<int> subList;
    int elem = 0;
    int i = 0;
    int minElem = 0;
    int maxElem = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Generate singly linked list.";
        cout << endl
             << "2. Traverse singly linked list.";
        cout << endl
             << "3. Take the element at the specified position.";
        cout << endl
             << "4. Set element value.";
        cout << endl
             << "5. Delete element.";
        cout << endl
             << "6. Insert element.";
        cout << endl
             << "7. Element positioning.";
        cout << endl
             << "8. Take the length of the singly linked list.";
        cout << endl
             << "9. In-situ invert.";
        cout << endl
             << "a. Delete the node between minimum element and maximum element.";
        cout << endl
             << "b. Combine two singly linked lists in increasing order into one singly linked list in decreasing order.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select function(0~b): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << endl
                 << "Input a element (exit when value = 0): ";
            cin >> elem;
            while (elem != 0)
            {
                list.AppendElem(elem);
                cin >> elem;
            }
            list.Swap(0, 5);
            break;
        case '2':
            list.Traverse();
            break;
        case '3':
            cout << endl
                 << "Enter element position: ";
            cin >> i;
            try
            {
                elem = list.GetElem(i);
                cout << "Element: " << elem << endl;
            }
            catch (string &error)
            {
                cout << error;
            }
            break;
        case '4':
            cout << endl
                 << "Enter element position: ";
            cin >> i;
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            try
            {
                list.SetElem(i, elem);
            }
            catch (string &error)
            {
                cout << error;
            }
            break;
        case '5':
            cout << endl
                 << "Enter element position: ";
            cin >> i;
            try
            {
                list.DeleteElem(i);
            }
            catch (string &error)
            {
                cout << error;
            }
            break;
        case '6':
            cout << endl
                 << "Enter element position: ";
            cin >> i;
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            try
            {
                list.InsertElem(i, elem);
            }
            catch (string &error)
            {
                cout << error;
            }
            break;
        case '7':
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            i = list.GetIndex(elem);
            if (i == -1)
            {
                cout << "Element does not exist." << endl;
            }
            else
            {
                cout << "Index is: " << i << endl;
            }
            break;
        case '8':
            cout << endl
                 << "The length is: " << list.GetLength() << endl;
            break;
        case '9':
            list.Reverse();
            break;
        case 'a':
            cout << endl
                 << "Enter manimum element: ";
            cin >> minElem;
            cout << "Enter maximum element: ";
            cin >> maxElem;
            try
            {
                list.DeleteBetween(minElem, maxElem);
            }
            catch (string &error)
            {
                cout << error;
            }
            break;
        case 'b':
            subList.Clear();
            cout << endl
                 << "Input a element (exit when value = 0): ";
            cin >> elem;
            while (elem != 0)
            {
                subList.AppendElem(elem);
                cin >> elem;
            }
            list.Merge(subList);
            break;
        }
    }
    return 0;
}
