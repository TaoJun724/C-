#define _CRT_SECURE_NO_WARNINGS  0
#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;




class String
{
public:
	//不推荐此构造函数
	//String()
	//	:_str(new char[1])
	//{
	//	_str[0] = '\0';
	//}

	//String(char* str)
	//	:_str(new char[strlen(str) + 1])
	//{
	//	strcpy(_str, str);//可以拷贝'\0'
	//}




	//推荐使用全缺省构造函数
	String(char* str = "")//空的字符串
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);//可以拷贝'\0'
	}

	//深拷贝
	//传统写法
	/*String(const String& s)
	:_str(new char[strlen(s._str)+1])
	{
	strcpy(_str,s._str);
	}*/

	//现代写法
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//赋值
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}



	~String()
	{
		delete[] _str;
	}
	char* c_str()
	{
		return _str;
	}


private:
	char* _str;

};