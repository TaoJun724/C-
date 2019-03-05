#include<iostream>
#include<stdlib.h>
#include<mutex>
using namespace std;


class Singleton
{
public:
	static Singleton* GetInstance(){
		//使用双锁，可以提高效率，如果没有双检查，原本并行的现场到这里都变成串行的，保证线程的安全性
		if (nullptr == m_pInstance){
			m_mtx.lock();//一次进一个
			if (nullptr == m_pInstance){
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return  m_pInstance;
	}

	//程序在结束的时候，系统会自动析构所有的全局变量和所有的类的静态成员变量。
	//实现一个内嵌垃圾回收类，删除实例的对象。
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
	//Singleton& operator=(const Singleton&);//声明不定义
	
	// 防拷贝 C++11
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* m_pInstance; // 单例对象指针   
	static mutex m_mtx;            //互斥锁 



};

Singleton* Singleton::m_pInstance = nullptr; 
Singleton::CGarbo Garbo; 
mutex Singleton::m_mtx;

