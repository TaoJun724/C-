#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//
//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		// 这里如果系统内存不够也会抛异常
//		//v.reserve(1000000000);//bad allocation
//		// 这里越界会抛异常
//		v.at(10) = 100;//invalid vector<T>subscript
//		//v[10] = 10;//断言处理所以会直接报错
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;//本质上e.what()是个多态  
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}//
//	system("pause");
//	return 0;
//}




//同时有父类同时有子类
//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		// 这里如果系统内存不够也会抛异常
//		//v.reserve(1000000000);//bad allocation
//		// 这里越界会抛异常
//		v.at(10) = 100;//invalid vector<T>subscript
//		//v[10] = 10;//断言处理所以会直接报错
//	}
//
//	catch (const bad_alloc& e)
//	{
//		cout << e.what() << endl;//同时有父类同时有子类会跳到这里
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;//本质上e.what()是个多态  
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}//
//	system("pause");
//	return 0;
//}