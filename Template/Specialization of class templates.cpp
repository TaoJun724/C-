#include<iostream>
#include<stdlib.h>
using namespace std;

//��ģ���ػ�
//ȫ�ػ�
//template<class  T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<>
//class Data<int, char>
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	int  _d1;
//	char _d2;
//};
//
//void Test2()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}


//ƫ�ػ�
//template<class T1,class T2>
//class Data
//{
//public:
//	Data(){ cout << "Data1<T1,T2>" << endl;}
//private:
//	T1 _d1;
//	T2 _d2;
//};

//ƫ�ػ��Ĳ����ػ�
//template<class T1>
//class Data<T1, int>
//{
//public:
//	Data(){ cout << "Data<T1,int>" << endl;}
//private:
//	T1 _d1;
//	int _d2;
//};

//ƫ�ػ������Ľ�һ������

//���������ػ���ָ������
//template<class T1,class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data()
//	{
//		cout << "(T1*,T2*)" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//};
//���������ػ�Ϊ��������
//template<class T1,class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data()
//	{
//		cout << "(T1&,T2&)" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//};

//
//void Test3()
//{
//	Data<int, double> a1;
//	Data<int*, int*> a2;
//	Data<int&, int&> a3;
//	Data<char, int> a4;
//}


