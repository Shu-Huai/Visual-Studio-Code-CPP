#include "SeqList.h"
#include "SeqStack.h"
#include <iostream>
using namespace std;
double StringToDouble(string num)
{
    bool minus = false;
    string real = num;
    if (num.at(0) == '-')
    {
        minus = true;
        real = num.substr(1, num.size() - 1);
    }
    char c;
    int i = 0;
    double result = 0.0, dec = 10.0;
    bool isDec = false;
    unsigned long size = real.size();
    while (i < size)
    {
        c = real.at(i);
        if (c == '.')
        {
            isDec = true;
            i++;
            continue;
        }
        if (!isDec)
        {
            result = result * 10 + c - '0';
        }
        else
        {
            result = result + (c - '0') / dec;
            dec *= 10;
        }
        i++;
    }
    if (minus == true)
    {
        result = -result;
    }

    return result;
}
bool IsOperator(string s)
{
    if (s == "#" || s == "(" || s == "^" || s == "*" || s == "/" || s == "+" || s == "-" || s == ")")
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class ElemType>
ElemType Operate(ElemType first, string s, ElemType second)
{
    ElemType result;
    if (s == "+")
    {
        return first + second;
    }
    if (s == "-")
    {
        return first - second;
    }
    if (s == "*")
    {
        return first * second;
    }
    if (s == "/")
    {
        return first / second;
    }
    if (s == "6")
    {
        return pow(first, second);
    }
    return 0;
}
void Evaluation(SequenceList<string> &ExpressList)
{
    SeqStack<double> ExpressStack;
    int length = ExpressList.GetLength();
    char ch = 0;
    int i = 0;
    string perm = "";
    ExpressList.GetElem(i + 1, perm);
    while (perm != "#")
    {
        if (IsOperator(perm))
        {
            double first;
            double second;
            ExpressStack.Pop(second);
            ExpressStack.Pop(first);
            ExpressStack.Push(Operate(first, perm, second));
        }
        else
        {
            double operand = StringToDouble(perm);
            ExpressStack.Push(operand);
        }
        i++;
        ExpressList.GetElem(i + 1, perm);
    }
    double result;
    ExpressStack.Pop(result);
    cout << "表达式结果为: " << result << endl;
}
int main()
{
    SequenceList<string> input(DEFAULT_SIZE);
    cout << "输入后缀表达式，以'#'号结束:" << endl;
    string s = "\0";
    while (s != "#")
    {
        cin >> s;
        input.AppendElem(s);
    }
    Evaluation(input);
    return 0;
}