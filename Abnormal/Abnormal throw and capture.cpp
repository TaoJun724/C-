#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


//�쳣��ͨ���׳������������
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
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
//�쳣��ͨ���׳�����������ģ��ö�������;�����Ӧ�ü����ĸ�catch�Ĵ�����롣 
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	//throw 10;//ƥ��
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
//	catch (int e)//������ƥ��
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




//��ѡ�еĴ�������ǵ���������ö�������ƥ�������׳��쳣λ���������һ����
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
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
//	catch (const char* errmsg)//���
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
//	catch (const char* errmsg)//�����ִ��
//	{
//		cout << errmsg << endl;
//	}
//
//
//	system("pause");
//}




//�׳��쳣����󣬻�����һ���쳣����Ŀ�������Ϊ�׳����쳣���������һ����ʱ�������Ի�����
//һ���������������������ʱ������ڱ�catch�Ժ����١�������Ĵ��������ں����Ĵ�ֵ���أ�//�쳣û�б�������������ֹ
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		string errmsg( "Division by zero condition!");
//		throw errmsg;//���������������һ����ʱ����
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
//	catch (const char* errmsg)//���
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
//	//û��������������
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//
//
//
//	system("pause");
//}