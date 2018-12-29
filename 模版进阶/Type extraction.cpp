#include<iostream>
#include<stdlib.h>
using namespace std;



//内置类型
class TrueType
{
public:
	static bool Get()
	{
		return true;
	}
};
//自定义类型
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
T为int：TypeTraits<int>已经特化过，程序运行时就会使用已经特化过的TypeTraits<int>, 该类中的
IsPODType刚好为类TrueType，而TrueType中Get函数返回true，内置类型使用memcpy方式拷贝

T为string：TypeTraits<string>没有特化过，程序运行时使用TypeTraits类模板, 该类模板中的IsPODType
刚
好为类FalseType，而FalseType中Get函数返回true，自定义类型使用赋值方式拷贝
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