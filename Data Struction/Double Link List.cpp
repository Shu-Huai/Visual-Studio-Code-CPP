#include "Double Link List.h"
int main()
{
    char functionSelect = 0;
    DoubleLinkList<double> doubleLinkList;
    double elem = 0;
    int index = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Generate a double link list.";
        cout << endl
             << "2. Display the double link list.";
        cout << endl
             << "3. Get an element.";
        cout << endl
             << "4. Set the value of an element.";
        cout << endl
             << "5. Delete an element.";
        cout << endl
             << "6. Insert an element.";
        cout << endl
             << "7. Locate an element.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select funtion (0~7): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            doubleLinkList.Clear();
            cout << endl
                 << "Input a element (exit when element = 0): ";
            cin >> elem;
            while (elem != 0)
            {
                doubleLinkList.AppendElem(elem);
                cin >> elem;
            }
            break;
        case '2':
            doubleLinkList.Traverse();
            break;
        case '3':
            cout << endl
                 << "Input the index: ";
            cin >> index;
            try
            {
                elem = doubleLinkList.GetElem(index);
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
                 << "Input the index: ";
            cin >> index;
            cout << endl
                 << "Input the value: ";
            cin >> elem;
            try
            {
                doubleLinkList.SetElem(index, elem);
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
                 << "Input the index: ";
            cin >> index;
            try
            {
                doubleLinkList.DeleteElem(index);
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
                 << "Input the index: ";
            cin >> index;
            cout << endl
                 << "Input the value: ";
            cin >> elem;
            try
            {
                doubleLinkList.InsertElem(index, elem);
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
                 << "Input the value: ";
            cin >> elem;
            index = doubleLinkList.GetIndex(elem);
            if (index == 0)
                cout << "The element does not exist." << endl;
            else
                cout << "The index is: " << index << endl;
            break;
        }
    }
    return 0;
}
