


//�麯������д

#include<stdlib.h>
#include<iostream>
using namespace std;


class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫƱ" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ" << endl;
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
