#include <iostream>
using namespace std;
class RMB
{
public:
    RMB()
    {
        y = 0;
        j = 0;
        f = 0;
    }
    RMB(int yuan, int jiao, int fen)
    {
        y = yuan;
        j = jiao;
        f = fen;
    }
    RMB(double yuan)
    {
        y = yuan;
        j = yuan * 10 - y * double(10);
        f = yuan * 100 - y * double(100) - j * double(10);
    }

private:
    int y, j, f;
};
int main()
{
    RMB moren;
    RMB sange(1, 2, 3);
    RMB zhuanhuan(2.46);
    return 0;
}