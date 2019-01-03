#include<iostream>
#include<stdlib.h>
using namespace std;

//没有使用虚拟继承时
//class A
//{
//public:
//	int a;
//};
//
//class B :public A
//{
//public:
//	int b;
//};
//
//class C :public A
//{
//public:
//	int c;
//};
//
//class D:public B,public C
//{
//public:
//	int d;
//};
//
//void test()
//{
//	D d;
//	d.B::a = 1;
//	d.C::a = 2;
//	d.b = 3;
//	d.c = 4;
//	d.d = 5;
//}


//当使用虚拟菱形继承时
//class A
//{
//public:
//	int a;
//};
//
//class B : virtual public A
//{
//public:
//	int b;
//};
//
//class C : virtual public A
//{
//public:
//	int c;
//};
//
//class D : public B, public C
//{
//public:
//	int d;
//};
//
//void test()
//{
//		D d;
//		d.B::a = 1;
//		d.C::a = 2;
//		d.b = 3;
//		d.c = 4;
//		d.d = 5;
//}
//int main()
//{	
//	test();
//	system("pause");
//}