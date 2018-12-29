#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


//如何实现一个通用的拷贝函数
//1）memcpy拷贝
////可以对所有的内置类型进行拷贝，是一种浅拷贝，但是如果对一些自定义类型，存在资源管理进行拷贝，就会出现问题，因为这是一种深拷贝。
template<class T>
void Copy1(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

//2）赋值方式拷贝
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


//Pod( plain old data )--基本类型
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
//通过typeid来确认所拷贝对象的实际类型，然后再在内置类型集合中枚举其是否出现过，既可确认所拷贝元
//素的类型为内置类型或者自定义类型。但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比
//较，效率比较低。
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
