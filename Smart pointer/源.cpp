#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;


//RAII���������ָ���˼��
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


	//��ָ��һ��
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


//���������һ��������free,�ڶ����������freeǰ�����쳣��ȫ��
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	SmartPtr<int> sp(tmp);
	_MergeSort(a, 0, n - 1, tmp);




	//�쳣��ȫ
	vector<int> v(1000000000, 10);//��ͳ�ķ�ʽ�޷����free�ͷ�

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

	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ
	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
	AutoPtr(AutoPtr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = nullptr;
	}
	


	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		// ����Ƿ�Ϊ�Լ����Լ���ֵ
		if (this != &ap)
		{
			// �ͷŵ�ǰ��������Դ
			if (_ptr)
				delete _ptr;

			// ת��ap����Դ����ǰ������
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

	//����Ȩת��
	auto_ptr<Date> ap(new Date);

	auto_ptr<Date> copy(ap);

	//ap->_year = 2073;//����������auto_ptr��ԭ���������Ϊ��copy������ǳ������������ap��Ϊempty��
}

void Test4()
{
	AutoPtr<Date> sp(new Date);
	AutoPtr<Date> copy(sp);


	//����Ȩת�ƣ�һ����Ҫʹ��AutoPtr
	AutoPtr<Date> sp1(new Date);
	copy = sp1;
}

void Test5()
{
	// unique_ptr�����˼·�ǳ��Ĵֱ�-��������Ҳ���ǲ��ÿ����͸�ֵ�� 
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
	//û����������ȷֻ���ɺ�
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
		// ��������ʹ�ü�1��ԭ�Ӳ���
		_pMutex->lock();
		++(*_pCount);		_pMutex->unlock();
		return *_pCount;
	}
	int SubRefCount()
	{
		// ��������ʹ�ü�1��ԭ�Ӳ���
		_pMutex->lock();
		--(*_pCount);
		_pMutex->unlock();
		return *_pCount;
	}
	//sp1=sp2
	//CAS֧��ԭ����  �Ƚ���  �����Ļ�����
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		//��������ͬʱ
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
//	//shared_ptr��ԭ����ͨ�����ü����ķ�ʽ��ʵ�ֶ��shared_ptr����֮�乲����Դ.
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
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		SharedPtr<Date> copy(sp);
		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ��������տ����Ľ������һ���Ǽ���2n
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}


//�̰߳�ȫ����    ++ --  ʹ����
void Test8()
{
	SharedPtr<Date> p(new Date);
	const size_t n = 10000;//��Խ���̰߳�ȫ������׳���
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);
	t1.join();
	t2.join();

	cout << p.UseCount() << endl;//��ʱ����������ʱ��������

	cout << p->_year << endl;;//�̲߳���ȫ
}


int main()
{
	Test8();
	system("pause");
}