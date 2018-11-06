//懒汉模式
//优点：第一次使用实例对象时，创建对象
//缺点：复杂

#include<iostream>
#include<stdlib.h>
#include<mutex>
using namespace std;


class Singleton
{
public:
	static Singleton* GetInstance(){
		//使用双锁
		if (nullptr == m_pInstance){
			m_mtx.lock();
			if (nullptr == m_pInstance){
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return  m_pInstance;
	}


	//实现一个内嵌垃圾回收类
	class CGarbo{
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;


private:   
	// 构造函数私有  
	Singleton(){};

	 //防拷贝 C++98
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);
	
	// 防拷贝 C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* m_pInstance; // 单例对象指针   
	static mutex m_mtx;            //互斥锁 



};

Singleton* Singleton::m_pInstance = nullptr; 
Singleton::CGarbo Garbo; 
mutex Singleton::m_mtx;





int main()
{
	//Singleton copy(*Singleton::GetInstance());//该句会出错
	system("pause");
	return 0;
}