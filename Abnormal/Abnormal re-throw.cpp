#include<iostream>
#include<stdlib.h>
using namespace std;


double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];



	//��a~b֮��������쳣�������ڴ�й©��//�쳣��ȫ����
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
	
	//���
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		delete[] array;
		cout << "delete[]" << array<<endl;

		throw ;//����Ϊ�˴����쳣����Ϊ������ִ����
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