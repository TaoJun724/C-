#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//
//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		// �������ϵͳ�ڴ治��Ҳ�����쳣
//		//v.reserve(1000000000);//bad allocation
//		// ����Խ������쳣
//		v.at(10) = 100;//invalid vector<T>subscript
//		//v[10] = 10;//���Դ������Ի�ֱ�ӱ���
//	}
//	catch (const exception& e) // ���ﲶ�������Ϳ���
//	{
//		cout << e.what() << endl;//������e.what()�Ǹ���̬  
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}//
//	system("pause");
//	return 0;
//}




//ͬʱ�и���ͬʱ������
//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		// �������ϵͳ�ڴ治��Ҳ�����쳣
//		//v.reserve(1000000000);//bad allocation
//		// ����Խ������쳣
//		v.at(10) = 100;//invalid vector<T>subscript
//		//v[10] = 10;//���Դ������Ի�ֱ�ӱ���
//	}
//
//	catch (const bad_alloc& e)
//	{
//		cout << e.what() << endl;//ͬʱ�и���ͬʱ���������������
//	}
//	catch (const exception& e) // ���ﲶ�������Ϳ���
//	{
//		cout << e.what() << endl;//������e.what()�Ǹ���̬  
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}//
//	system("pause");
//	return 0;
//}