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
//	//ADD(a, d);����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	//ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//
//
//	//����һ���û��Լ���ǿ��ת��
//	ADD(a, (int)d);
//	//������:��ʾʵ����
//	ADD<int>(a, d);
//	system("pause");
//	return 0;
//}


//һ����ģ�庯�����Ժ�һ��ͬ���ĺ���ģ��ͬʱ���ڣ����Ҹú���ģ�廹���Ա�ʵ����Ϊ�����ģ��//����
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


//���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ���ڵ���ʱ�����ȵ��÷�ģ�庯��������Ӹ�ģ�������һ��ʵ�������ģ����Բ���һ�����и���ƥ��ĺ����� ��ô��ѡ��ģ��
//
//
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}//////int main()//{//	Test();//	system("pause");//	return 0;//}//��ʽָ��һ���յ�ģ��ʵ���б����﷨���߱�����ֻ��ģ�������ƥ��������ã� �������е�ģ�������Ӧ�ø���ʵ���������//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add<>(1, 2); // ����ģ�����ɵ�Add����
//}//////int main()//{//	Test();//	system("pause");//	return 0;//}//ģ�庯���������Զ�����ת��������ͨ�������Խ����Զ�����ת��