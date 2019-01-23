#include"String.h"






void test121()
{

	char a1[] = "\0";//Ò»¸ö×Ö·û
	cout << sizeof(a1) << endl;//2
	cout << strlen(a1) << endl;//0

	char a2[] = "\\0";
	cout << sizeof(a2) << endl;//3 
	cout << strlen(a2) << endl;//2

	char a3[] = "\\0";
	cout << sizeof(a3) << endl;//3
	cout << strlen(a3) << endl;//2


	char a4[] = "0000";
	cout << sizeof(a4) << endl;//5
	cout << strlen(a4) << endl;//4



	char a5[] = "\0000";
	cout << sizeof(a5) << endl;//3
	cout << strlen(a5) << endl;//0


	char a6[] = "\0 000";
	cout << sizeof(a6) << endl;
	cout << strlen(a6) << endl;

}



void test22()
{
	String s1("hello");
	String s2(s1);
	cout << s1.c_str() << endl;
}
int main()
{
	test22();
	system("pause");
}