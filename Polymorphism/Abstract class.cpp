#include<stdlib.h>
#include<iostream>
using namespace std;



class Car
{
public:
	virtual void Func() = 0;//纯虚函数
};

class ACar:public Car
{
public:
	virtual void Func()
	{
		cout << "大气" << endl;
	}
};

class BCar : public Car
{
public:
	virtual void Func()
	{
		cout << "低调" << endl;
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