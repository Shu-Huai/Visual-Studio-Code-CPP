#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
public:
    Complex()
    {
        re = 0;
        im = 0;
    }
    Complex(double real, double imag)
    {
        re = real;
        im = imag;
    }
    double Real() const
    {
        return re;
    }
    double Imag() const
    {
        return im;
    }
    double Radius() const
    {
        return sqrt(re * re + im * im);
    }
    double Angle() const
    {
        return atan(im / re) * 180.0 / 3.1416;
    }
    void Set1(double real, double imag)
    {
        re = real;
        im = imag;
    }
    void Set2(double radius, double angle)
    {
        im = sin(angle) * radius;
        re = cos(angle) * radius;
    }
    void Show1() const
    {
        cout << "The complex is ";
        if (re == 0)
        {
        }
        else
        {
            cout << re;
        }
        if (im == 0)
        {
        }
        else if (im == 1)
        {
            cout << " + i.";
        }
        else if (im == -1)
        {
            cout << " - i.";
        }
        else
        {
            cout << " + " << im << "i.";
        }
        cout << endl;
    }
    void Show2() const
    {
        cout << "The complex is " << Radius() << "e^i" << atan(im / re) * 180.0 / 3.1416 << endl;
    }
    Complex &operator*=(const Complex &c)
    {
        Complex result;
        result.re = re * c.re - im * c.im;
        result.im = re * c.im + im * c.re;
        re = result.re;
        im = result.im;
        return *this;
    }

private:
    double re, im;
};
class Rational
{
public:
    Rational()
    {
        fenzi_ = 0.0;
        fenmu_ = 0.0;
    }
    Rational(double fenzi, double fenmu)
    {
        fenzi_ = fenzi;
        fenmu_ = fenmu;
    }
    double zi() const
    {
        return fenzi_;
    }
    double mu() const
    {
        return fenmu_;
    }
    void set(double fenzi, double fenmu)
    {
        fenzi_ = fenzi;
        fenmu_ = fenmu;
    }
    void Show() const
    {
        cout << "The rational is ";
        if (fenmu_ == 0)
        {
            cout << "not exsiting";
        }
        else if (fenmu_ == 1)
        {
            cout << fenzi_ << "." << endl;
        }
        else
        {
            cout << fenzi_ << " / " << fenmu_ << "." << endl;
        }
    }

private:
    double fenzi_, fenmu_;
};
int main()
{
    Complex number1(3, 4);
    Complex number2;
    number1.Show1();
    number1.Show2();
    cout << "The real od the complex is " << number1.Real() << endl
         << "The imag of the complex is " << number1.Imag() << endl
         << "The radius of the complex is " << number1.Radius() << endl
         << "The angle of the complex is " << number1.Angle() << endl;
    number2.Set1(1, 1);
    number2.Show1();
    number2.Set2(1.414, 3.1416 / 4);
    number2.Show1();
    Complex test0(3, 4);
    Complex test1(1, 2);
    test0 *= test1;
    test0 *= test0;
    Rational number3(2, 5);
    Rational number4;
    number3.Show();
    number4.set(5, 1);
    number4.Show();
    return 0;
}