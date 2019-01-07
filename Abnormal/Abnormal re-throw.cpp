#include<iostream>
#include<stdlib.h>
using namespace std;


double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];



	//在a~b之间可能抛异常，导致内存泄漏。//异常安全问题
	//a
	/*try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}                                                      
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}*/
	//b
	
	//解决
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		delete[] array;
		cout << "delete[]" << array<<endl;

		throw ;//不是为了处理异常而是为了拦截执行流
	}



	cout << "delete[]" << array << endl;
	delete[] array;
}

//
//int main()
//{
//	try{
//		Func();
//	}
//
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	
//	system("pause");
//}