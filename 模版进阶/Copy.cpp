#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


//���ʵ��һ��ͨ�õĿ�������
//1��memcpy����
////���Զ����е��������ͽ��п�������һ��ǳ���������������һЩ�Զ������ͣ�������Դ������п������ͻ�������⣬��Ϊ����һ�������
template<class T>
void Copy1(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//2����ֵ��ʽ����
template<class T>
void Copy2(T* dst, T* src, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		dst[i] = src[i];
	}
}
void test2()
{
	string  arr1[3] = { "aa", "bb", "cc" };
	string  arr2[3];
	Copy2(arr2, arr1, 3);
	cout << arr2[0] << endl;
}


//Pod( plain old data )--��������
bool IsPodType(const char* strType)
{
	const char* arrType[] = { "char", "int", "double", \
		"short", "float", "long", "long long", "long double" };
	for (int i = 0; i < sizeof(arrType) / sizeof(arrType[0]); i++)
	{
		if (0 == strcmp(arrType[i], strType))
			return true;
	}
	return false;
}
//ͨ��typeid��ȷ�������������ʵ�����ͣ�Ȼ�������������ͼ�����ö�����Ƿ���ֹ����ȿ�ȷ��������Ԫ
//�ص�����Ϊ�������ͻ����Զ������͡���ȱ���ǣ�ö����Ҫ���������ͱ���һ�飬ÿ�αȽ϶����ַ����ı�
//�ϣ�Ч�ʱȽϵ͡�
//template<class T>
//void Copy3(T* dst, T* src, size_t size)
//{
//	if (IsPodType(typeid(T).name())
//	{
//		memcpy(dst, src, sizeof(T)*size);
//	}
//	else
//	{
//		for (int i = 0; i < size; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//
