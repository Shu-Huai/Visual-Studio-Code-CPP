#include <cmath>
#include <iostream>
using namespace std;
class Point
{
private:
    double x, y;

public:
    Point(double X = 0.0, double Y = 0.0);
    friend double GetDistance(Point &coordinate1, Point &coordinate2);
};
Point::Point(double X, double Y)
{
    x = X;
    y = Y;
}
double GetDistance(Point &coordinate1, Point &coordinate2)
{
    double distance = pow(pow((coordinate1.x - coordinate2.x), 2) + pow((coordinate1.y - coordinate2.y), 2), 0.5);
    return distance;
}
int main()
{
    Point test0(0, 0);
    Point test1(3, 4);
    double distance = GetDistance(test0, test1);
    return 0;
}