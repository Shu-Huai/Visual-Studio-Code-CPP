#include"LinkList.h"
#include <iostream>
int main()
{
	int a[4] = { 3,4,5,6 };
	int b[5] = { 4,5,6,7,8 };
	LinkList<int> la(a, 4);
	LinkList<int> lb(b, 5);
	la.Show();
	lb.Show();
	la.Merge(lb);
	la.Show();
	return 0;
}