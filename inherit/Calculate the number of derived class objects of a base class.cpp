#include<iostream>
#include<stdlib.h>
using namespace std;



class  A
{
public:
	A()
	{
		++count;
	}
public:
	static int count;
protected:
	int name;
};

//��̬��Ա�����ⶨ��
int A::count = 0;
class B : public A
{};

class C : public A
{};




//
//int main()
//{
//	B b;
//	C c;
//	cout << A::count << endl;
//	system("pause");
//}