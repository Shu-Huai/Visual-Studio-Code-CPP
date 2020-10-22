#include <iostream>
#ifndef TEST_H
#define TEST _H
using namespace std;
namespace mySpace
{
    class Test
    {
    public:
        Test(int x = 0);
        void Set(int x);
        int Get() const;
        void Show() const;

    private:
        int a;
    };
} // namespace mySpace
#endif
mySpace::Test::Test(int x)
{
    a = x;
}
void mySpace::Test::Set(int x)
{
    a = x;
}
int mySpace::Test::Get() const
{
    return a;
}
void mySpace::Test::Show() const
{
    cout << a << endl;
}
int main()
{
    mySpace::Test Test2020(2020);
    Test2020.Set(2020);
    cout << "The number is: " << Test2020.Get() << endl;
    Test2020.Show();
    mySpace::Test Test2019(2019);
    Test2019.Set(2019);
    cout << "The number is: " << Test2019.Get() << endl;
    Test2019.Show();
    return 0;
}