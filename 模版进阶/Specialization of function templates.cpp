#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;



//函数模版特化
template<class T>
bool IsEqual(T& x1, T& x2)
{
	return x1 == x2;
}

template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) == 0)
		return true;

	return false;
}
template<>
bool IsEqual<int>(int& left, int& right)
{
	if (left == right)
		return true;

	return false;
}
void Test1()
{
	char* s1 = "hehe";
	char* s2 = "hehe";

	if (IsEqual(s1, s2))
		cout << "Equal" << endl;
	else
		cout << "No Equal" << endl;

	int x = 0;
	int y = 1;
	if (IsEqual(x, y))
		cout << "Equal" << endl;
	else
		cout << "No Equal" << endl;

}


