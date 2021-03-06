// C++第四次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Rational
{
private:
	int m;                              //分子
	int n;                              //分母
public:
	Rational(int mm = 0, int nn = 0);
	Rational operator + (Rational &a);  //加法
	Rational operator - (Rational &a);  //减法
	Rational operator * (Rational &a);  //乘法
	Rational operator / (Rational &a);  //除法
	Rational operator -();              //取反
	Rational operator ++();             //前置自增
	Rational operator ++(int);          //后置自增
	Rational operator --();             //前置自减
	Rational operator --(int);          //后置自减
	friend ostream& operator << (ostream& output, Rational&a);   //输出	
	void simple();                      //化简
};
Rational::Rational(int mm, int nn)
{
	if (nn == 0)
	{
		nn = 1;
	}
	m = mm;
	n = nn;
}
Rational Rational::operator +(Rational &a)
{
	Rational c;
	c.m = m * a.n + a.m*n;
	c.n = n * a.n;
	c.simple();
	return c;
}
Rational Rational::operator-(Rational &a)
{
	Rational c;
	c.m = m * a.n - a.m*n;
	c.n = n * a.n;
	c.simple();
	return c;
}
Rational Rational::operator*(Rational &a)
{
	Rational c;
	c.m = m * a.m;
	c.n = n * a.n;
	c.simple();
	return c;
}
Rational Rational::operator/(Rational &a)
{
	Rational c;
	c.m = m * a.n;
	c.n = n * a.m;
	c.simple();
	return c;
}
Rational Rational::operator -()
{
	Rational a(-m, n);
	a.simple();
	return a;

}
Rational Rational::operator ++()
{
	m = m + n;
	simple();
	return *this;
}
Rational Rational::operator++(int)
{
	Rational temp(m, n);
	m = m + n;
	simple();
	return temp;
}
Rational Rational::operator--()
{
	m = m - n;
	simple();
	return *this;
}
Rational Rational::operator--(int)
{
	Rational temp(m, n);
	m = m - n;
	simple();
	return temp;
}
ostream& operator <<(ostream& output, Rational &a)
{
	if (a.n < 0)
		output << -a.m << "/" << -a.n << endl;
	else
		output << a.m << "/" << a.n << endl;
	return output;
}
void Rational::simple()
{
	int a = m, b = n, t;
	if (m < n)
	{
		a = n;
		b = m;
	}
	while (1)
	{
		t = a % b;
		if (t == 0) break;
		a = b;
		b = t;
	}
	m = m / b;
	n = n / b;
}
int main()
{
	Rational a(4, 6), b(2, -1), c;
	c = a + b;
	cout << c;
	c = a - b;
	cout << c;
	c = a * b;
	cout << c;
	c = a / b;
	cout << c;
	c = -a;
	cout << c;
	c = ++a;
	cout << "a:" << a << "c:" << c;
	c = a++;
	cout << "a:" << a << "c:" << c;
	c = --a;
	cout << "a:" << a << "c:" << c;
	c = a--;
	cout << "a:" << a << "c:" << c;
	cin.get();
}