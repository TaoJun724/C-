#include<iostream>
#include<stdlib.h>
using namespace std;



//T ADD(const T& a, const T& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	double c = 1.3;
//	double d = 2.0;
//	ADD(a, b);
//	ADD(c, d);
//	//ADD(a, d);该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	//通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//
//
//	//方法一：用户自己来强制转化
//	ADD(a, (int)d);
//	//方法二:显示实例化
//	ADD<int>(a, d);
//	system("pause");
//	return 0;
//}


//一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板//函数
//int Add(int a, int b)
//{
//	return a + b;
//}
//template<class T>
//T Add(const T a, const T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	Add(1, 2);
//	double a =Add<double>(2.3, 4.5);
//	cout << "a" << endl;
//	system("pasue");
//	return  0;
//}


//对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
//
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}//////int main()//{//	Test();//	system("pause");//	return 0;//}//显式指定一个空的模板实参列表，该语法告诉编译器只有模板才能来匹配这个调用， 而且所有的模板参数都应该根据实参演绎出来//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add<>(1, 2); // 调用模板生成的Add函数
//}//////int main()//{//	Test();//	system("pause");//	return 0;//}//模板函数不允许自动类型转换，但普通函数可以进行自动类型转换