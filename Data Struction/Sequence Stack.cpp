#include "Sequence Stack.h"
int main()
{
    char functionSelect = 0;
    SequenceStack<int> stack;
    int elem = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Generate stack.";
        cout << endl
             << "2. Traverse stack.";
        cout << endl
             << "3. Take the top element of the stack.";
        cout << endl
             << "4. Push into the stack.";
        cout << endl
             << "5. Pop.";
        cout << endl
             << "6. Find the length of the chain stack.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select function (0~6): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            stack.Clear();
            cout << endl
                 << "Input a value (exit when value = 0): ";
            cin >> elem;
            while (elem)
            {
                try
                {
                    stack.Push(elem);
                }
                catch (string &error)
                {
                    cout << error << endl;
                    break;
                }
            }
            break;
        case '2':
            stack.Traverse();
            break;
        case '3':
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
        case '4':
            cout << endl
                 << "Enter element: ";
            cin >> elem;
            try
            {
                stack.Push(elem);
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
                stack.Pop();
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
                 << "The length of the stack is: " << stack.GetLength() << endl;
            break;
        }
    }
    return 0;
}