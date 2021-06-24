#include "String.h"
int main()
{
    String string("It is a car.");
    String subString;
    char functionSelect = 0;
    int index = 0;
    int length = 0;
    char character = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成字符串。";
        cout << endl
             << "2. 遍历字符串。";
        cout << endl
             << "3. 插入子串。";
        cout << endl
             << "4. 删除子串。";
        cout << endl
             << "5. 取字符串长度。";
        cout << endl
             << "6. 取子串。";
        cout << endl
             << "7. 拷贝字符串。";
        cout << endl
             << "8. 比较字符串。";
        cout << endl
             << "9. 取字符下标。";
        cout << endl
             << "a. 模式匹配。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~a）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << "输入字符串：";
            cin >> string;
            cout << "成功。" << endl;
            break;
        case '2':
            string.Traverse();
            break;
        case '3':
            cout << "输入字串：";
            cin >> subString;
            cout << "输入下标：";
            cin >> index;
            try
            {
                string.InsertString(subString, index);
            }
            catch (std::string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '4':
            cout << "输入下标：";
            cin >> index;
            cout << "输入长度：";
            cin >> length;
            string.DeleteString(index, length);
            break;
        case '5':
            cout << "字符串的长度为：" << string.GetLength() << "。" << endl;
            break;
        case '6':
            cout << "输入下标：";
            cin >> index;
            cout << "输入长度：";
            cin >> length;
            try
            {
                subString = string.GetSubString(index, length);
            }
            catch (std::string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "子串为：" << subString << "。" << endl;
            break;
        case '7':
            cout << "输入字符串：";
            cin >> subString;
            string.Copy(subString);
            cout << "成功。" << endl;
            break;
        case '8':
            cout << "输入字符串：";
            cin >> subString;
            cout << "比较结果为：" << string.Compare(subString) << "。" << endl;
            break;
        case '9':
            cout << "输入字符：";
            cin >> character;
            index = string.GetIndex(character);
            if (index == -1)
            {
                cout << "字符不存在。" << endl;
            }
            else
            {
                cout << "下标是：" << index << "。" << endl;
            }
            break;
        case 'a':
            cout << "输入子串：";
            cin >> subString;
            index = string.KMPPatternMatching(subString);
            if (index == -1)
            {
                cout << "字符不存在。" << endl;
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