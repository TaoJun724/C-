//多态原理

#include<iostream>
#include<stdlib.h>
using namespace std;

class Person
{
public :
	virtual void Ticket() = 0;//纯虚函数
};

class Parent :public Person
{
public:
	virtual void Ticket()
	{
		cout << "全票" << endl;
	}
};
class Stu :public Person
{
public:
	virtual void Ticket()
	{
		cout << "半票" << endl;
	}
};
void Func5(Person& p)
{
	p.Ticket();
}
void test()
{
	Parent p;
	Stu s;
	Func5(p);
	Func5(s);
}

//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}