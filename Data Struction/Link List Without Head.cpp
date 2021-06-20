#include "Link List Without Head.h"
int main()
{
    char functionSelect = 0;
    LinkListWithoutHead<int> list;
    LinkListWithoutHead<int> subList;
    int elem;
    int index;
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
             << "9. In situ inverse.";
        cout << endl
             << "b. Combine two singly linked lists in increasing order into one singly linked list in decreasing order.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select function (0~b): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << endl
                 << "Input a element (exit when value = 0): ";
            cin >> elem;
            while (elem)
            {
                list.AppendElem(elem);
                cin >> elem;
            }
            break;
        case '2':
            list.Traverse();
            break;
        case '3':
            cout << endl
                 << "Enter element position: ";
            cin >> index;
            try
            {
                elem = list.GetElem(index);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "Element: " << elem << endl;
            break;
        case '4':
            cout << endl
                 << "Enter element position: ";
            cin >> index;
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            try
            {
                list.SetElem(index, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '5':
            cout << endl
                 << "Enter element position: ";
            cin >> index;
            try
            {
                list.DeleteElem(index);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '6':
            cout << endl
                 << "Enter element position: ";
            cin >> index;
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            try
            {
                list.InsertElem(index, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '7':
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            index = list.GetIndex(elem);
            if (index == -1)
            {
                cout << "Element does not exist." << endl;
            }
            else
            {
                cout << "The index is: " << index << endl;
            }
            break;
        case '8':
            cout << endl
                 << "The length of the singly linked list is: " << list.GetLength() << endl;
            break;
        case '9':
            list.Reverse();
            cout << endl
                 << "The singly linked list has been inverted." << endl;
            break;
        case 'b':
            subList.Clear();
            cout << endl
                 << "Input a element (exit when value = 0): ";
            cin >> elem;
            while (elem)
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
