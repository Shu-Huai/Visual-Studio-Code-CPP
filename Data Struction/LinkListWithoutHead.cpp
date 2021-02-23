#include "LinkList.h"
int main()
{
	char c = 0;
	LinkList<double> LL0;
	LinkList<double> LL1;
	double e;
	int i;
	double s = 0;
	double t = 0;
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
			 << "b. 将两个递增有序的单链表合并为一个递减有序的单链表.";
		cout << endl
			 << "0. 退出";
		cout << endl
			 << "选择功能(0~b):";
		cin >> c;
		switch (c)
		{
		case '1':
			LL0.Clear();
			cout << endl
				 << "输入e(e = 0时退出):";
			cin >> e;
			while (e != 0)
			{
				LL0.InsertElem(e);
				cin >> e;
			}
			break;
		case '2':
			LL0.Traverse(Write<double>);
			break;
		case '3':
			cout << endl
				 << "输入元素位置:";
			cin >> i;
			if (LL0.GetElem(i, e) == RANGE_ERROR)
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
			if (LL0.SetElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "设置成功." << endl;
			break;
		case '5':
			cout << endl
				 << "输入位置:";
			cin >> i;
			if (LL0.DeleteElem(i, e) == RANGE_ERROR)
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
			if (LL0.InsertElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "成功:" << e << endl;
			break;
		case '7':
			cout << endl
				 << "输入元素的值:";
			cin >> e;
			i = LL0.LocateElem(e);
			if (i == 0)
				cout << "元素不存在." << endl;
			else
				cout << "元素" << e << "的序号为：" << i << endl;
			break;
		case '8':
			cout << endl
				 << "单链表的长度为:" << LL0.GetLength() << endl;
			break;
		case '9':
			LL0.Reverse();
			cout << endl
				 << "已将单链表逆置." << endl;
			break;
		case 'b':
			LL1.Clear();
			cout << endl
				 << "输入e(e = 0时退出):";
			cin >> e;
			while (e != 0)
			{
				LL1.InsertElem(e);
				cin >> e;
			}
			LL0.Merge(LL1);
			break;
		}
	}
	return 0;
}
