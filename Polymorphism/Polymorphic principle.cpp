//��̬ԭ��

#include<iostream>
#include<stdlib.h>
using namespace std;

class Person
{
public :
	virtual void Ticket() = 0;//���麯��
};

class Parent :public Person
{
public:
	virtual void Ticket()
	{
		cout << "ȫƱ" << endl;
	}
};
class Stu :public Person
{
public:
	virtual void Ticket()
	{
		cout << "��Ʊ" << endl;
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