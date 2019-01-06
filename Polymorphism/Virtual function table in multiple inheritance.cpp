#include<iostream>
#include<stdlib.h>
using namespace std;






class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};


typedef void(*VFUNC)();

void PrintVTable2(VFUNC table[])
{
	printf("���ָ�룺%p\n", table);
	for (size_t i = 0; table[i] != nullptr; ++i)
	{
		printf("vtable[%d];%p->", i, table[i]);
		VFUNC vf = table[i];
		vf();
	}
}


void A()
{
	cout << sizeof(Derive) << endl;//20  ��һ��������8 �ڶ���������8 ���Լ��õĸ��������ټ����Լ��ĳ�Ա�������ĸ��ֽڣ�������20.
}

void B()
{
	Derive d;
	PrintVTable2((VFUNC*)(*(int*)&d));
	//PrintVTable2((VFUNC*)(*(int*)(&d+sizeof(Base1))));//�������������ԭ������Ϊ&d��������Derive*,��1�ӵ���20
	PrintVTable2((VFUNC*)(*(int*)((char*)&d + sizeof(Base1))));
}
int main()
{
	B();
	system("pause");
	return 0;
}