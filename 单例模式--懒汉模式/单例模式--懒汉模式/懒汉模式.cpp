//����ģʽ
//�ŵ㣺��һ��ʹ��ʵ������ʱ����������
//ȱ�㣺����

#include<iostream>
#include<stdlib.h>
#include<mutex>
using namespace std;


class Singleton
{
public:
	static Singleton* GetInstance(){
		//ʹ��˫��
		if (nullptr == m_pInstance){
			m_mtx.lock();
			if (nullptr == m_pInstance){
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return  m_pInstance;
	}


	//ʵ��һ����Ƕ����������
	class CGarbo{
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;


private:   
	// ���캯��˽��  
	Singleton(){};

	 //������ C++98
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);
	
	// ������ C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* m_pInstance; // ��������ָ��   
	static mutex m_mtx;            //������ 



};

Singleton* Singleton::m_pInstance = nullptr; 
Singleton::CGarbo Garbo; 
mutex Singleton::m_mtx;





int main()
{
	//Singleton copy(*Singleton::GetInstance());//�þ�����
	system("pause");
	return 0;
}