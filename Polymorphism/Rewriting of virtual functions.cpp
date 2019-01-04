


//虚函数的重写

#include<stdlib.h>
#include<iostream>
using namespace std;


class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全票" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半票" << endl;
	}
};

void Func(Person& p)
{
	p.BuyTicket();
}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	system("pause");
//	return 0;
//}
//
