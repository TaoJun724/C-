//饿汉模式
//优点：简单
//缺点：可能会导致启动慢







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

	//Singleton& GetInstance()
	//{
	//	return m_Instance;
	//}//使用会出错


private:
	Singleton()
	{}

	//防拷贝C++98
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);

	//防拷贝C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

	static Singleton  m_instance;

};

Singleton Singleton::m_instance;

int main()
{
	//Singleton copy(*Singleton::GetInstance());//该句会出错
	system("pause");
	return 0;
}