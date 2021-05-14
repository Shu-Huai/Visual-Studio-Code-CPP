#include <iostream>
using namespace std;
int main()
{
    int N = 1;
    cin >> N;
    getchar();
    int count = 1;
    string s[2];
    while (count <= N)
    {
        cin >> s[0] >> s[1];
        if (s[0] == "Rock" && s[1] == "Scissors")
        {
            cout << "Player1";
        }
        if (s[0] == "Rock" && s[1] == "Rock")
        {
            cout << "Tie";
        }
        if (s[0] == "Rock" && s[1] == "Paper")
        {
            cout << "Player2";
        }
        if (s[0] == "Scissors" && s[1] == "Rock")
        {
            cout << "Player2";
        }
        if (s[0] == "Scissors" && s[1] == "Scissors")
        {
            cout << "Tie";
        }
        if (s[0] == "Scissors" && s[1] == "Paper")
        {
            cout << "Player1";
        }
        if (s[0] == "Paper" && s[1] == "Scissors")
        {
            cout << "Player2";
        }
        if (s[0] == "Paper" && s[1] == "Paper")
        {
            cout << "Tie";
        }
        if (s[0] == "Paper" && s[1] == "Rock")
        {
            cout << "Player1";
        }
        count++;
        cout << endl;
    }
    return 0;
}