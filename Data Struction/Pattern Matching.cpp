#include "Pattern Matching.h"
int main()
{
    string ob;
    string pat;
    char functionSelect = 0;
    int index = 0;
    while (functionSelect != '0')
    {
        cout << "1. 第一个模式匹配。";
        cout << endl
             << "2. 第二个模式匹配。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~2）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << "输入字符串：";
            cin >> ob;
            cout << "输入模式串：";
            cin >> pat;
            index = PatternMatching::BruteForcePatternMatching(ob, pat);
            if (index==-1)
            {
                cout << "不存在。" << endl;
            }
            else
            {
                cout << "下标是：" << index << "。" << endl;
            }
            break;
        case '2':
            cout << "输入字符串：";
            cin >> ob;
            cout << "输入模式串：";
            cin >> pat;
            index = PatternMatching::KMPPatternMatching(ob, pat);
            if (index == -1)
            {
                cout << "不存在。" << endl;
            }
            else
            {
                cout << "下标是：" << index << "。" << endl;
            }
            break;
        }
    }
    return 0;
}