#include <iostream>
using namespace std;
bool BashGame(int number)
{
    return number % 4 != 0;
}
int main()
{
    int number = 0;
    int count = 0;
    while (cin >> number)
    {
        cout << "Case " << ++count << endl
             << BashGame(number) << endl;
    }
    return 0;
}