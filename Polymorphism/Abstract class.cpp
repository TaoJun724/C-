#include<stdlib.h>
#include<iostream>
using namespace std;



class Car
{
public:
	virtual void Func() = 0;//���麯��
};

class ACar:public Car
{
public:
	virtual void Func()
	{
		cout << "����" << endl;
	}
};

class BCar : public Car
{
public:
	virtual void Func()
	{
		cout << "�͵�" << endl;
	}
};

//int main()
//{
//	Car* a = new ACar;
//	a->Func();
//
//	Car* b = new BCar;
//	b->Func();
//
//	system("pause");
//	return 0;
//}