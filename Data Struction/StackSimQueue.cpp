#include "SeqStack.h"
class StackSimQueue
{
protected:
    SeqStack<int> SS1_;
    SeqStack<int> SS2_;

public:
    StackSimQueue(int size = DEFAULT_SIZE);
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const int &));
    Status EnQueue(const int e);
    Status DelQueue(int &e);
};
StackSimQueue::StackSimQueue(int size) : SS1_(size), SS2_(size)
{
}
int StackSimQueue::GetLength() const
{
    return SS1_.GetLength();
}
bool StackSimQueue::IsEmpty() const
{
    return SS1_.IsEmpty();
}
void StackSimQueue::Clear()
{
    SS1_.Clear();
}
void StackSimQueue::Traverse(void (*Visit)(const int &))
{
    int length = SS1_.GetLength();
    for (int i = 0; i < length; i++)
    {
        int temp;
        SS1_.Pop(temp);
        SS2_.Push(temp);
    }
    SS2_.Traverse(Write<int>);
    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        SS2_.Pop(temp);
        SS1_.Push(temp);
    }
}
Status StackSimQueue::EnQueue(const int e)
{
    return SS1_.Push(e);
}
Status StackSimQueue::DelQueue(int &e)
{
    int length = SS1_.GetLength();
    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        SS1_.Pop(temp);
        SS2_.Push(temp);
    }
    Status sta = SS2_.Pop(e);
    for (int i = 0; i < length - 1; i++)
    {
        int temp = 0;
        SS2_.Pop(temp);
        SS1_.Push(temp);
    }
    return sta;
}
int main()
{
    char c = 0;
    StackSimQueue SSQ;
    int e = 0;
    Status sta;
    while (c != '0')
    {
        cout << endl
             << "1. 生成队列.";
        cout << endl
             << "2. 显示队列.";
        cout << endl
             << "3. 入队.";
        cout << endl
             << "4. 出队.";
        cout << endl
             << "5. 求队列长度.";
        cout << endl
             << "6. 判断列空.";
        cout << endl
             << "0. 退出.";
        cout << endl
             << "选择功能(0~5):";
        cin >> c;
        switch (c)
        {
        case '1':
            SSQ.Clear();
            sta = SUCCESS;
            cout << endl
                 << "输入e(e = 0时退出):";
            cin >> e;
            while (e != 0 && sta != OVER_FLOW)
            {
                sta = SSQ.EnQueue(e);
                if (sta == OVER_FLOW)
                {
                    cout << "顺序栈已满." << endl;
                }
                else
                {
                    cin >> e;
                }
            }
            break;
        case '2':
            SSQ.Traverse(Write<int>);
            break;
        case '3':
            cout << endl
                 << "输入e:";
            cin >> e;
            if (SSQ.EnQueue(e) == UNDER_FLOW)
            {
                cout << "顺序栈空." << endl;
            }
            else
            {
                cout << "已入栈." << endl;
            }
            break;
        case '4':
            if (SSQ.DelQueue(e) == UNDER_FLOW)
            {
                cout << "顺序栈空." << endl;
            }
            else
            {
                cout << "已出栈." << endl
                     << "元素:" << e << endl;
            }
            break;
        case '5':
            cout << endl
                 << "顺序栈的长度为:" << SSQ.GetLength() << endl;
            break;
        case '6':
            if (SSQ.IsEmpty())
            {
                cout << endl
                     << "列空." << endl;
            }
            else
            {
                cout << endl
                     << "列非空." << endl;
            }
            break;
        }
    }
    return 0;
}