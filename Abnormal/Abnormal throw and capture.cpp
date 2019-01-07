#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


//异常是通过抛出对象而引发的
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch  (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//
//	system("pause");
//}



//
//异常是通过抛出对象而引发的，该对象的类型决定了应该激活哪个catch的处理代码。 
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	//throw 10;//匹配
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (int e)//参数不匹配
//	{
//		cout << e << endl;
//	}
//}
//
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//
//	system("pause");
//}




//被选中的处理代码是调用链中与该对象类型匹配且离抛出异常位置最近的那一个。
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg)//这个
//	{
//		cout << errmsg << endl;
//	}
//}
//
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)//这个不执行
//	{
//		cout << errmsg << endl;
//	}
//
//
//	system("pause");
//}




//抛出异常对象后，会生成一个异常对象的拷贝，因为抛出的异常对象可能是一个临时对象，所以会生成
//一个拷贝对象，这个拷贝的临时对象会在被catch以后销毁。（这里的处理类似于函数的传值返回）//异常没有被捕获则会程序终止
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		string errmsg( "Division by zero condition!");
//		throw errmsg;//除了作用域会生成一个临时拷贝
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg)//这个
//	{
//		cout << errmsg << endl;
//	}
//}
//
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	//没有这个则程序会崩溃
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//
//
//	system("pause");
//}