#include "Link Stack.h"
int main()
{
    char functionSelect = 0;
    LinkStack<int> stack;
    int elem;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Build stack.";
        cout << endl
             << "2. Traverse stack.";
        cout << endl
             << "3. Push.";
        cout << endl
             << "4. Pop.";
        cout << endl
             << "5. Get stack top.";
        cout << endl
             << "0. Exit";
        cout << endl
             << "Select function (0~5): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            stack.Clear();
            cout << "Input a element (exit when element = 0): " << endl;
            cin >> elem;
            while (elem != 0)
            {
                stack.Push(elem);
                cin >> elem;
            }
            break;
        case '2':
            cout << endl;
            stack.Traverse();
            break;
        case '3':
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            stack.Push(elem);
            break;
        case '4':
            try
            {
                stack.Pop();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "Succeeded." << endl;
            break;
        case '5':
            try
            {
                elem = stack.Top();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "The element is: " << elem << endl;
            break;
        }
    }
    return 0;
}