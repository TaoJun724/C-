//Ðé±í

#include<iostream>
#include<stdlib.h>
using namespace std;


class A
{
public:
	virtual void Func1()
	{
		cout << "A::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "B::Func2()" << endl;
	}

	void Fun3()
	{
		cout << "A::Func3" << endl;
	}
	
private:
	int a;
};

class B:public A
{
public:
	virtual void Func1()
	{
		cout << "B::Func1()" << endl;
	}
private:
	int b;
};

//int main()
//{
//	A  a;
//	B  b;
//	system("pasue");
//	return 0;
//}
//
