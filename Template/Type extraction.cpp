#include<iostream>
#include<stdlib.h>
using namespace std;



//��������
class TrueType
{
public:
	static bool Get()
	{
		return true;
	}
};
//�Զ�������
class FalseType
{
public:
	static bool Get()
	{
		return false;
	}
};


template<class T>
class TypeTraits
{
public:
	typedef FalseType IsPodType;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType  IsPodType;
};

template<>
class TypeTraits<int>
{
public:
	typedef TrueType IsPodType;
};


template<>
class TypeTraits<char>
{
public:
	typedef TrueType IsPodType;
};

template<>
class TypeTraits<float>
{
public:
	typedef TrueType IsPodType;
};

template<>
class TypeTraits<double>
{
public:
	typedef TrueType IsPodType;
};

template<>
class TypeTraits<long>
{
public:
	typedef TrueType IsPodType;
};

template<>
class TypeTraits<long long>
{
public:
	typedef TrueType IsPodType;
};

template<>
class TypeTraits<long double>
{
public:
	typedef TrueType IsPodType;
};



/*
TΪint��TypeTraits<int>�Ѿ��ػ�������������ʱ�ͻ�ʹ���Ѿ��ػ�����TypeTraits<int>, �����е�
IsPODType�պ�Ϊ��TrueType����TrueType��Get��������true����������ʹ��memcpy��ʽ����

TΪstring��TypeTraits<string>û���ػ�������������ʱʹ��TypeTraits��ģ��, ����ģ���е�IsPODType
��
��Ϊ��FalseType����FalseType��Get��������true���Զ�������ʹ�ø�ֵ��ʽ����
*/
template<class T>
void Copy4(T* dst, T* src, size_t size)
{
	if (TypeTraits<T>::IsPodType::Get())
	{
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10];
	Copy4(a2, a1, 10);

	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy4(s2, s1, 4);
	system("pause");
	return 0;
}