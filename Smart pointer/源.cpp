#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;


//RAII是设计智能指针的思想
template<class T>
class SmartPtr
{
public:
	//RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete" << _ptr << endl;
		delete _ptr;
	}


	//像指针一样
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};



void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right) return;

	int mid = left + ((right - left) >> 1);
	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}


//两种情况第一种是忘记free,第二种情况是在free前存在异常安全。
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	SmartPtr<int> sp(tmp);
	_MergeSort(a, 0, n - 1, tmp);




	//异常安全
	vector<int> v(1000000000, 10);//传统的方式无法完成free释放

	// free(tmp);
}

void Test0()
{
	try{
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);

		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//void Test1()
//{
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//	sp1.operator*() = 20;
//	cout << *sp1 << endl;
//
//	SmartPtr<Date> sp2(new Date);
//	sp2->_month = 1;
//	sp2->_day = 2;//sp2.operator->()->day = 2;
//	(*sp2)._year = 2019;
//}

#include<memory>
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year = 0;
	int _month = 0;
	int _day = 0;
};



template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}

	~AutoPtr()
	{
		delete _ptr;
	}

	T& operator*()
	{
		return _ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系
	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
	AutoPtr(AutoPtr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = nullptr;
	}
	


	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		// 检测是否为自己给自己赋值
		if (this != &ap)
		{
			// 释放当前对象中资源
			if (_ptr)
				delete _ptr;

			// 转移ap中资源到当前对象中
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		return *this;
	}



private:
	T* _ptr;
};
void Test3()
{

	//管理权转移
	auto_ptr<Date> ap(new Date);

	auto_ptr<Date> copy(ap);

	//ap->_year = 2073;//程序会崩溃，auto_ptr的原理决定，因为它copy构造是浅拷贝。拷贝后ap变为empty。
}

void Test4()
{
	AutoPtr<Date> sp(new Date);
	AutoPtr<Date> copy(sp);


	//管理权转移，一定不要使用AutoPtr
	AutoPtr<Date> sp1(new Date);
	copy = sp1;
}

void Test5()
{
	// unique_ptr的设计思路非常的粗暴-防拷贝，也就是不让拷贝和赋值。 
	unique_ptr<Date> up(new Date);
}




#include<mutex>
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pCount(new int(1))
		, _pMutex(new mutex)
	{}

	~SharedPtr()
	{
		//if (--*_pCount == 0)
		if (this->SubRefCount() == 0)
		{
			delete _ptr;
			delete _pCount;
			delete _pMutex;
		}
	}
	//没有这个结果正确只是巧合
	SharedPtr(const SharedPtr<T>& sp)
	{
		_ptr = sp._ptr;
		_pCount = sp._pCount;
		//++(*_pCount);
		_pMutex = sp._pMutex;
		AddRefCount();
	}



	int AddRefCount()
	{
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pCount);		_pMutex->unlock();
		return *_pCount;
	}
	int SubRefCount()
	{
		// 加锁或者使用减1的原子操作
		_pMutex->lock();
		--(*_pCount);
		_pMutex->unlock();
		return *_pCount;
	}
	//sp1=sp2
	//CAS支持原子性  比较轻  而锁的话很重
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		//当两个相同时
		if (_ptr != sp._ptr)
		{
			//if (--(*_pCount) == 0)
			if (this->SubRefCount()==0)
			{
				delete _ptr;
				delete _pCount;
				delete _pMutex;
			}

			_ptr = sp._ptr;
			_pCount = sp._pCount;
			//++(*_pCount);

			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}
	
	int UseCount()
	{
		return *_pCount;
	}

	T& operator*()
	{
		return *_ptr;
	}


	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _pCount;
	mutex* _pMutex;
};


//void Test6()
//{
//	shared_ptr<Date> sp(new Date);
//	shared_ptr<Date> copy(sp);
//
//	sp->_year = 20185
//
//	cout << copy->_year << endl;
//
//	//shared_ptr的原理：是通过引用计数的方式来实现多个shared_ptr对象之间共享资源.
//	cout << sp.use_count() << endl;
//	cout << copy.use_count() << endl;
//}




void Test7()
{
	SharedPtr<Date> sp(new Date);
	sp->_month = 2018;

	SharedPtr<Date> copy(sp);
	cout << copy->_month << endl;

	sp = copy;
}



#include<thread>
void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		SharedPtr<Date> copy(sp);
		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}


//线程安全问题    ++ --  使用锁
void Test8()
{
	SharedPtr<Date> p(new Date);
	const size_t n = 10000;//数越大线程安全会更容易出现
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);
	t1.join();
	t2.join();

	cout << p.UseCount() << endl;//有时候析构，有时候不析构。

	cout << p->_year << endl;;//线程不安全
}


int main()
{
	Test8();
	system("pause");
}