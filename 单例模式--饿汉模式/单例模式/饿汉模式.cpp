//����ģʽ
//�ŵ㣺��
//ȱ�㣺���ܻᵼ��������







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
	//}//ʹ�û����


private:
	Singleton()
	{}

	//������C++98
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);

	//������C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

	static Singleton  m_instance;

};

Singleton Singleton::m_instance;

int main()
{
	//Singleton copy(*Singleton::GetInstance());//�þ�����
	system("pause");
	return 0;
}