#define _CRT_SECURE_NO_WARNINGS  0
#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;




class String
{
public:
	//���Ƽ��˹��캯��
	//String()
	//	:_str(new char[1])
	//{
	//	_str[0] = '\0';
	//}

	//String(char* str)
	//	:_str(new char[strlen(str) + 1])
	//{
	//	strcpy(_str, str);//���Կ���'\0'
	//}




	//�Ƽ�ʹ��ȫȱʡ���캯��
	String(char* str = "")//�յ��ַ���
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);//���Կ���'\0'
	}

	//���
	//��ͳд��
	/*String(const String& s)
	:_str(new char[strlen(s._str)+1])
	{
	strcpy(_str,s._str);
	}*/

	//�ִ�д��
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//��ֵ
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