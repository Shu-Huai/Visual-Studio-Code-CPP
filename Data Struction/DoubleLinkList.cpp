#include "DoubleLinkList.h"
int main()
{
	char c = 0;
	DoubleLinkList<double> DLL0;
	double e = 0;
	int i = 0;
	while (c != '0')
	{
		cout << endl
			 << "1. 生成循环双链表.";
		cout << endl
			 << "2. 显示循环双链表.";
		cout << endl
			 << "3. 取指定元素值.";
		cout << endl
			 << "4. 设置元素值.";
		cout << endl
			 << "5. 删除元素.";
		cout << endl
			 << "6. 插入元素.";
		cout << endl
			 << "7. 元素定位.";
		cout << endl
			 << "0. 退出";
		cout << endl
			 << "选择功能(0~7):";
		cin >> c;
		switch (c)
		{
		case '1':
			DLL0.Clear();
			cout << endl
				 << "输入e(e = 0时退出):";
			cin >> e;
			while (e != 0)
			{
				DLL0.InsertElem(e);
				cin >> e;
			}
			break;
		case '2':
			DLL0.Traverse(Write<double>);
			break;
		case '3':
			cout << endl
				 << "输入元素位置:";
			cin >> i;
			if (DLL0.GetElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
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
			if (DLL0.SetElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "设置成功." << endl;
			break;
		case '5':
			cout << endl
				 << "输入位置:";
			cin >> i;
			if (DLL0.DeleteElem(i, e) == RANGE_ERROR)
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
			if (DLL0.InsertElem(i, e) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "成功:" << e << endl;
			break;
		case '7':
			cout << endl
				 << "输入元素值:";
			cin >> e;
			i = DLL0.LocateElem(e);
			if (i == 0)
				cout << "指定元素不存在." << endl;
			else
				cout << "指定元素的序号为：" << i << endl;
			break;
		}
	}
	return 0;
}
