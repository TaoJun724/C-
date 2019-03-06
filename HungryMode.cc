#include<iostream>
#include<stdlib.h>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}

	//static Singleton& GetInstance()
	//{
	//	return m_Instance;
	//}


private:
	Singleton()//构造函数私有化可以使别的地方不能创建对象
	{}

	//防拷贝C++98
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);//声明但不定义

	//防拷贝C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

	static Singleton  m_instance;

};

Singleton Singleton::m_instance;//main之前就创建

int main()
{
	//Singleton s1 = *Singleton::Getinstance();//运算符重载被显示的声明为已删除函数并且是私有的
	//Singleton copy(*Singleton::GetInstance());//该句会出错，拷贝构造已经私有化
	return 0;
}

