#include "LinkList.h" // 单链表类

int main(void)
{
	char c = '*';
	LinkList<double> la;
	double e;
	int i;
	double s = 0;
	double t = 0;
	LinkList<double> lb;
	while (c != '0')
	{
		cout << endl
			 << "1. 生成单链表.";
		cout << endl
			 << "2. 显示单链表.";
		cout << endl
			 << "3. 取指定位置的元素.";
		cout << endl
			 << "4. 设置元素值.";
		cout << endl
			 << "5. 删除元素.";
		cout << endl
			 << "6. 插入元素.";
		cout << endl
			 << "7. 元素定位";
		cout << endl
			 << "8. 取单链表长度";
		cout << endl
			 << "9. 原地逆置.";
		cout << endl
			 << "a. 删除s<e<t的结点.";
		cout << endl
			 << "b. 将两个递增有序的单链表合并为一个递减有序的单链表.";
		cout << endl
			 << "0. 退出";
		cout << endl
			 << "选择功能(0~b):";
		cin >> c;
		switch (c)
		{
		case '1':
			la.Clear();
			cout << endl
				 << "输入e(e = 0时退出):";
			cin >> e;
			while (e != 0)
			{
				la.InsertElem(e);
				cin >> e;
			}
			break;
		case '2':
			la.Traverse(Write<double>);
			break;
		case '3':
			cout << endl
				 << "输入元素位置:";
			cin >> i;
			if (la.GetElem(i, e) == RANGE_ERROR)
				cout << "元素不存在." << endl;
			else
				cout << "元素:" << e << endl;
			break;
		case '4':
			cout << endl
				 << "输入位置:";
			cin >> i;
			cout << endl
				 << "输入元素值:";
			cin >> e;
			if (la.SetElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "设置成功." << endl;
			break;
		case '5':
			cout << endl
				 << "输入位置:";
			cin >> i;
			if (la.DeleteElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "被删除元素值:" << e << endl;
			break;
		case '6':
			cout << endl
				 << "输入位置:";
			cin >> i;
			cout << endl
				 << "输入元素值:";
			cin >> e;
			if (la.InsertElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "成功:" << e << endl;
			break;
		case '7':
			cout << endl
				 << "输入元素的值:";
			cin >> e;
			i = la.LocateElem(e);
			if (i == 0)
				cout << "元素不存在." << endl;
			else
				cout << "元素" << e << "的序号为：" << i << endl;
			break;
		case '8':
			cout << endl
				 << "单链表的长度为:" << la.GetLength() << endl;
			break;
		case '9':
			la.Reverse();
			cout << endl
				 << "已将单链表逆置." << endl;
			break;
		case 'a':
			cout << endl
				 << "输入s的值:";
			cin >> s;
			cout << "输入t的值:";
			cin >> t;
			if (la.DeleteBetween(s, t) == SUCCESS)
			{
				cout << "已删除s<e<t的结点." << endl;
			}
			else
			{
				cout << "错误." << endl;
			}
			break;
		case 'b':
			lb.Clear();
			cout << endl
				 << "输入e(e = 0时退出):";
			cin >> e;
			while (e != 0)
			{
				lb.InsertElem(e);
				cin >> e;
			}
			la.Merge(lb);
			break;
		}
	}
	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
