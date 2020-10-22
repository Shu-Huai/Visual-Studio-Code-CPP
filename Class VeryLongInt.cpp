#pragma warning(disable : 4996)
#include <cstring>
#include <iostream>
using namespace std;
class VeryLongInt
{
private:
	char number[51] = {'\0'};

public:
	VeryLongInt(const char *Number = 0);
	VeryLongInt operator+(VeryLongInt num);
	VeryLongInt operator-(VeryLongInt num);
	VeryLongInt operator*(VeryLongInt num);
	VeryLongInt operator/(VeryLongInt num);
	bool operator>(VeryLongInt num);
	bool operator>=(VeryLongInt num);
	bool operator<(VeryLongInt num);
	bool operator<=(VeryLongInt num);
	bool operator==(VeryLongInt num);
	bool operator!=(VeryLongInt num);
	void operator=(VeryLongInt num);
	VeryLongInt operator+=(VeryLongInt num);
	void operator-=(VeryLongInt num);
	VeryLongInt &operator++();
	VeryLongInt &operator--();
	VeryLongInt operator++(int);
	VeryLongInt operator--(int);
	friend istream &operator>>(istream &in, VeryLongInt &num);
	friend ostream &operator<<(ostream &out, const VeryLongInt &num);
};
VeryLongInt::VeryLongInt(const char *Number)
{
	strcpy(number, Number);
}
VeryLongInt VeryLongInt::operator+(VeryLongInt num)
{
	int originlen = strlen(number);
	int length = originlen < strlen(num.number) ? originlen : strlen(num.number);
	for (int i = 0; i < length; i++)
	{
		number[strlen(number) - i - 1] += num.number[strlen(num.number) - i - 1] - 48;
		int temp = 0;
	jinwei:
		if (number[strlen(number) - i - 1 - temp] > '9')
		{
			number[strlen(number) - i - 1 - temp] -= 10;
			if (strlen(number) - i - 1 - temp != 0)
			{
				number[strlen(number) - i - 2 - temp]++;
				temp++;
				goto jinwei;
			}
			else
			{
				number[originlen + (temp == 0 ? 0 : 1)] = '\0';
				for (int j = originlen + (temp == 0 ? 0 : 1); j > 0; j--)
				{
					number[j] = number[j - 1];
				}
				if (originlen > strlen(num.number))
				{
					number[0] += 1;
				}
				if (originlen = strlen(num.number))
				{
					number[0] = '1';
				}
				else
				{
					number[0] = num.number[0] + 1;
				}
			}
		}
	}
	return *this;
}
VeryLongInt VeryLongInt::operator-(VeryLongInt num)
{
	char c[51];
	strcpy(c, num.number);
	int length = strlen(number);
	if (strlen(number) > strlen(num.number))
	{
		num.number[strlen(number)] = '\0';
		for (int i = 0; i < strlen(num.number); i++)
		{
			num.number[strlen(number) - i - 1] = c[strlen(c) - i - 1];
		}
		for (int i = 0; i < strlen(number) - strlen(c); i++)
		{
			num.number[i] = '0';
		}
	}
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[strlen(number) - i - 1] < num.number[strlen(num.number) - i - 1])
		{
			int temp = number[strlen(number) - i - 1] + 10 - num.number[strlen(num.number) - i - 1];
			number[strlen(number) - i - 2]--;
			c[i] = temp + 48;
		}
		else
		{
			c[i] = number[strlen(number) - i - 1] - num.number[strlen(num.number) - i - 1] + 48;
		}
		count++;
	}
	c[count] = '\0';
	for (int i = 0; i < strlen(number); i++)
	{

		number[i] = c[strlen(c) - i - 1];
	}
	int i = 0;
	for (i = 0; i < strlen(number); i++)
	{
		if (number[i] != '0')
		{
			break;
		}
	}
	for (int j = 0; j < strlen(number); j++)
	{
		number[j] = number[j + i];
	}
	if (number[0] == '\0')
	{
		number[0] = '0';
		for (int j = 1; j < 50; j++)
		{
			number[j] = '\0';
		}
	}
	return *this;
}
VeryLongInt VeryLongInt::operator*(VeryLongInt num)
{
	VeryLongInt temp = *this;
	while (num.number[0] != '0')
	{
		num--;
		*this + temp;
	}
	*this - temp;
	return *this;
}
VeryLongInt VeryLongInt::operator/(VeryLongInt num)
{
	VeryLongInt temp = *this;
	VeryLongInt result = ("0");
	while (temp.number[0] != '0')
	{
		result++;
		temp - num;
	}
	*this = result;
	return *this;
}
bool VeryLongInt::operator>(VeryLongInt num)
{
	if (*this >= num and *this != num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool VeryLongInt::operator>=(VeryLongInt num)
{
	if (strlen(number) >= strlen(num.number))
	{
		for (int i = 0; i < strlen(number); i++)
		{
			if (number[i] < num.number[i])
			{
				return 0;
				break;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
bool VeryLongInt::operator<(VeryLongInt num)
{
	if (*this >= num)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool VeryLongInt::operator<=(VeryLongInt num)
{
	if (*this > num)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool VeryLongInt::operator==(VeryLongInt num)
{
	if (strlen(number) == strlen(num.number))
	{
		for (int i = 0; i < strlen(number); i++)
		{
			if (number[i] != num.number[i])
			{
				return 0;
				break;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
bool VeryLongInt::operator!=(VeryLongInt num)
{
	if (*this == num)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void VeryLongInt::operator=(VeryLongInt num)
{
	int i = 0;
	for (i = 0; i < (strlen(number) > strlen(num.number) ? strlen(number) : strlen(num.number)); i++)
	{
		number[i] = num.number[i];
	}
	for (int j = i; j < 50; j++)
	{
		number[j] = '\0';
	}
}
VeryLongInt VeryLongInt::operator+=(VeryLongInt num)
{
	*this + num;
	return *this;
}
void VeryLongInt::operator-=(VeryLongInt num)
{
	*this = *this - num;
}
VeryLongInt &VeryLongInt::operator++()
{
	VeryLongInt temp = ("1");
	*this = *this + temp;
	return *this;
}
VeryLongInt &VeryLongInt::operator--()
{
	VeryLongInt temp = ("1");
	*this = *this - temp;
	return *this;
}
VeryLongInt VeryLongInt::operator++(int)
{
	VeryLongInt temp(*this);
	++(*this);
	return temp;
}
VeryLongInt VeryLongInt::operator--(int)
{
	VeryLongInt temp(*this);
	--(*this);
	return temp;
}
istream &operator>>(istream &in, VeryLongInt &num)
{
	char temp[100] = {'\0'};
	in.getline(temp, '\n');
	num = VeryLongInt(temp);
	return in;
}
ostream &operator<<(ostream &out, const VeryLongInt &num)
{
	for (int i = 0; i < strlen(num.number); i++)
	{
		out << num.number[i];
	}
	return out;
}
int main()
{
	VeryLongInt test0("991");
	VeryLongInt test1("9");
	bool test2 = 0;
	test0 = test0 + test1;
	test0 = test0 - test1;
	test0 = test0 * test1;
	test0 = test0 / test1;
	test2 = (test0 > test1);
	test2 = (test0 >= test1);
	test2 = (test0 < test1);
	test2 = (test0 <= test1);
	test2 = (test0 == test1);
	test2 = (test0 != test1);
	test0 = test1;
	test0 += test1;
	test0 -= test1;
	++test0;
	--test0;
	test0++;
	test0--;
	cin >> test0;
	cout << test0;
	return 0;
}