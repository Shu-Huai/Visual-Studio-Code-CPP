#include "SeqStack.h"
#include <iostream>
using namespace std;
bool IsOperator(char ch)
{
    if (ch == '#' || ch == '(' || ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class ElemType>
ElemType Operate(ElemType first, char ch, ElemType second)
{
    ElemType result;
    switch (ch)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    case '^':
        return pow(first, second);
    default:
        return 0;
    }
}
void Evaluation(string Express)
{
    SeqStack<double> Expr;
    char ch = 0;
    while (ch != '#')
    {
        ch = GetChar();
        if (ch == '#')
        {
            break;
        }
        else if (isdigit(ch) || ch == '.')
        {
            double operand = 0;
            cin.putback(ch);
            cin >> operand;
            Expr.Push(operand);
        }
        else if (IsOperator(ch))
        {
            double first;
            double second;
            Expr.Pop(second);
            Expr.Pop(first);
            Expr.Push(Operate(first, ch, second));
        }
        else
        {
            throw Error("表达式中有非法符号!");
        }
    }
    double result;
    Expr.Pop(result);
    cout << "表达式结果为: " << result << endl;
}
int main()
{
    string input;
    getline(cin, input);
    Evaluation(input);
    return 0;
}