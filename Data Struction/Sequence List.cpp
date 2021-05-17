#include "Sequence List.h"
int main()
{
    char functionSelect = 0;
    SequenceList<int> SL;
    int elem = 0;
    int i = 0;
    double minimumValue = 0;
    double maximumValue = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Generate a sequence list.";
        cout << endl
             << "2. Display the sequence table.";
        cout << endl
             << "3. Take a specified element.";
        cout << endl
             << "4. Set a element value.";
        cout << endl
             << "5. Delete a element.";
        cout << endl
             << "6. Insert a element.";
        cout << endl
             << "7. Get the index of a elements. ";
        cout << endl
             << "8. Find the length of the sequence list.";
        cout << endl
             << "9. Remove duplicate elements.";
        cout << endl
             << "a. Reverse in situ.";
        cout << endl
             << "b. Delete the elements in the specified range.";
        cout << endl
             << "c. Sort.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select function (0~c): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            SL.Clear();
            cout << endl
                 << "Input a element (exit when elem = 0): ";
            cin >> elem;
            while (elem != 0)
            {
                try
                {
                    SL.AppendElem(elem);
                }
                catch (string &error)
                {
                    cout << error << "." << endl;
                    break;
                }
                cin >> elem;
            }
            break;
        case '2':
            SL.Traverse();
            break;
        case '3':
            cout << endl
                 << "Input the index of the element: ";
            cin >> i;
            try
            {
                elem = SL.GetElem(i);
            }
            catch (string &error)
            {
                cout << error << "." << endl;
                break;
            }
            cout << "Elements: " << elem << endl;
            break;
        case '4':
            cout << endl
                 << "Input the index of the element: ";
            cin >> i;
            cout << endl
                 << "Input the value of the element: ";
            cin >> elem;
            try
            {
                SL.SetElem(i, elem);
            }
            catch (string &error)
            {
                cout << error << "." << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '5':
            cout << endl
                 << "Input the index of the element: ";
            cin >> i;
            try
            {
                SL.DeleteElem(i);
            }
            catch (string &error)
            {
                cout << error << "." << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '6':
            cout << endl
                 << "Input the index of the element: ";
            cin >> i;
            cout << endl
                 << "Input the value of the element: ";
            cin >> elem;
            try
            {
                SL.InsertElem(i, elem);
            }
            catch (string &error)
            {
                cout << error << "." << endl;
                break;
            }
            cout << "Succeeded" << endl;
            break;
        case '7':
            cout << endl
                 << "Input the value of the element: ";
            cin >> elem;
            i = SL.LocateElem(elem);
            if (i != 0)
            {
                cout << "Element" << elem << "index is: " << i << "." << endl;
            }
            else
            {
                cout << "Element" << elem << "does not exist." << endl;
            }
            break;
        case '8':
            cout << endl
                 << "The length is: " << SL.GetLength() << endl;
            break;
        case '9':
            SL.DeleteRepeat();
            cout << endl
                 << "Succeeded" << endl;
            break;
        case 'a':
            SL.Reverse();
            cout << endl
                 << "Succeeded." << endl;
            break;
        case 'b':
            cout << endl
                 << "Input the maximum value: ";
            cin >> minimumValue;
            cout << "Input the minimum value: ";
            cin >> maximumValue;
            try
            {
                SL.DeleteBetween(minimumValue, maximumValue);
            }
            catch (string &error)
            {
                cout << error << "." << endl;
                break;
            }
            cout << "Deleted elements between " << minimumValue << " and " << maximumValue << "." << endl;
            break;
        case 'c':
            cout << endl;
            SL.Sort();
            cout << "Succeeded." << endl;
            break;
        }
    }
    return 0;
}