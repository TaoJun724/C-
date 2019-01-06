#include<iostream>
#include<stdlib.h>
using namespace std;


class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};


typedef void(*VFUNC)();

void PrintVTable1(VFUNC table[])
{
	printf("Ðé±íÖ¸Õë£º%p\n", table);
	for (size_t i = 0; table[i] != nullptr; ++i)
	{
		printf("vtable[%d];%p->", i, table[i]);
		VFUNC vf = table[i];
		vf();
	}
}



//int main()
//{
//	Base b;
//	PrintVTable1((VFUNC*)(*(int*)&b));
//	
//	Derive d;
//	PrintVTable1((VFUNC*)(*(int*)&d)); 
//
//	system("pause");
//	return 0;
//}