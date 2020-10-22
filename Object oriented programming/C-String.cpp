#include <iostream>
#include <cstdlib>
#include <cstring>
#include <conio.h>
using namespace std;
void test1(), test2();
void SWAP1();
void SWAP2_C();
void SWAP2_CPP();
void STRCAT_C();
void STRCAT_CPP();
void SWAP1(char *array1, char *array2)
{
	int length1=0;
	int length2=0;
	char temp[1000];
	while (array1[length1]!='\0')
	{
		temp[length1]=array1[length1];
		length1++;
	}
	while (array2[length2]!='\0')
	{
		length2++;
	}
	int times=0;
	if (length1>length2)
		times=length1;
	else
		times=length2;
	for (int i=0;i<times;i++)
	{
		array1[i]=array2[i];
	}
	for (int i=0;i<times;i++)
	{
		array2[i]=temp[i];
	}
}	
void SWAP2_C(char **p1, char **p2)
{
	char *temp	= *p1;
    *p1 = *p2;
    *p2 = temp;
}
void SWAP2_CPP(char **p1, char **p2)
{
	char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void STRCAT_C(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != 0)
    {
        i++;
    }
    str1[i] = '&';
    int j = 0;
    while (str2[j] != 0)
    {
        j++;
    }
    int k = 0;
    for (k = 0; k < j; k++)
    {
        str1[i + k + 1] = str2[k];
    }
    str1[k + 1 + i] = '\0';
}
void STRCAT_CPP(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != 0)
    {
        i++;
    }
    str1[i] = '&';
    int j = 0;
    while (str2[j] != 0)
    {
        j++;
    }
    int k = 0;
    for (k = 0; k < j; k++)
    {
        str1[i + k + 1] = str2[k];
    }
    str1[k + 1 + i] = '\0';
}
void test1()
{
	char array1[10]="Tom", array2[10]="Jerry";
	char *p1 = (char*)"Snoopy", *p2 = (char*)"Winnie";
	char *str1, *str2;
	cout << array1 << ", " << array2 << endl;
	SWAP1(array1,array2);
	cout << array1 << ", " << array2 << endl;
	cout << p1 << ", " << p2 << endl;
    SWAP2_C(&p1, &p2);
    cout << p1 << ", " << p2 << endl;
	p1 = (char*)"Snoopy";	p2 = (char*)"Winnie";
	cout << p1 << ", " << p2 << endl;
	SWAP2_CPP(&p1,&p2);
	cout << p1 << ", " << p2 << endl;
	str1 = new char[4];
	str2 = new char[6];
	strcpy(str1, "Tom");
	strcpy(str2, "Jerry");
	STRCAT_C(str1, str2);
	cout << str1 << endl;
	STRCAT_CPP(str1, str2);
	cout << str1 << endl;
	//delete [] str1;
	delete [] str2;
}
void SWAP2_1(char *p1, char *p2)
{
	char temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void SWAP2_3(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
 #define MAKE_DISTANCE
void test2()
{
#ifdef MAKE_DISTANCE
	char *p1 = (char*)"Tom", *p2 = new char[6];
	strcpy(p2, "Jerry");
#else
	char *p1 = "Tom", *p2 = "Jerry";
#endif
    char *q1 = p1, *q2 = p2;
    cout << "p1: " << p1 << ", p2: " << p2 << endl;
	SWAP2_3((int*)&p1, (int*)&p2);
	cout << "p1: " << p1 << ", p2: " << p2 << ".\t\t旁门左道！非正道到达目的\n" << endl;
	getch();
	cout << "执行前" << endl;
	p1 = q1; p2 = q2;
	cout << "p1 : " << p1 << ", p2 : " << p2 << endl;
	cout << "p1 = " << hex << (long long)p1 << ", p2 = " << (long long)p2 << dec << endl;
	SWAP2_1((char*)&p1, (char*)&p2);
	cout << "执行后" << endl;
	cout << "p1 : " << p1 << ", p2 : " << p2 << endl;
	cout << "！！！如果p1，p2存储的地址值仅低8位不同，则蒙混过关；否则p1,p2所存储的地址值都被改乱！！！" << endl;
	cout << "p1 = " << hex << (long long)p1 << ", p2 = " << (long long)p2 << dec << endl << endl;
	getch();
	cout << "执行前" << endl;
	p1 = q1; p2 = q2;
	cout << "p1: " << p1 << ", p2: " << p2 << endl;
	cout << "程序将遇到运行时错（Runtime error），因为p1指向常量字符串，不允许写操作。" << endl;
	cout << "下面将引起不可预料的结果。\n是否执行(y/[N])? " << endl;
	int key = getch();
	if(key=='y' || key=='Y')
	{
		SWAP2_1(p1, p2);
		cout << "执行后" << endl;
		cout << "p1: " << p1 << ", p2: " << p2 << endl;
	}
#ifdef MAKE_DISTANCE
	delete [] q2;
	cout << "\n释放所申请的堆内存单元。OK!" << endl;
#endif
}
int main()
{
    system("");
    int k;
	while(true)
	{
		cout << "\nC-String Testing 1 or 2, 0 -- exit? ";
		k = getch() - '0';
		if(k<=0) break;
		if(k==1) test1();
		if(k==2) test2();
	}
	return 0;
}