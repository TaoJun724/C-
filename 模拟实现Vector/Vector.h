#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __VECTOR__H__
#define __VECTOR_H__





#include<iostream>
#include<assert.h>
#include<stdlib.h>

using namespace std;
namespace TJ
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		Iterator begin()
		{
			return _start;
		}
		Iterator end()
		{
			return _finish;
		}

		typedef const T* Const_Iterator;
		Const_Iterator cbegin()const
		{
			return _start;
		}
		Const_Iterator cend()const
		{
			return _finish;
		}
		//无参构造
		Vector() :_start(nullptr), _finish(nullptr), _endofshort(nullptr)
		{
			
		}
		//构造并初识化n个value
		Vector(int n, const T& value = T()) :_start(nullptr), _finish(nullptr), _endofshort(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}
		//构造迭代器进行初始化构造
		Vector(Iterator begin, Iterator last) :_start(nullptr), _finish(nullptr), _endofshort(nullptr)
		{
			Reserve(last - begin);
			while (begin != last)
			{
				PushBack(*begin);
				++begin;
			}
		}

		//构造函数
		Vector(const Vector<T>& v) :_start(nullptr), _finish(nullptr), _endofshort(nullptr)
		{
			Reserve(v.Capacity());
			Iterator it = begin();
			Const_Iterator  cit = v.cbegin();
			while (cit != v.cend())
			{
				*it = *cit;
				++it;
				++cit;
			}
			_finish = _start + v.Size();
			_endofshort = _start + v.Capacity();
		}
		//析构函数
		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endofshort = nullptr;
			}
		}
		//size()
		size_t Size()const
		{
			return _finish - _start;
		}
		//capacity()
		size_t Capacity()const
		{
			return _endofshort - _start;
		}
		//判断是否为空
		bool Empty()
		{
			return Size() = 0 ? true : false;
		}
		//resize
		void Resize(size_t n, const T& value = T())
		{
			if (n < Size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n>Capacity())
				{
					Reserve(n);
				}
				Iterator it = _finish;
				_finish = _start + n;
				while (it != _finish)
				{
					*it = value;
					++it;
				}
			}
		}
		//reserve()
		void Reserve(size_t n)
		{
			if (n>Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < Size(); i++)
					{
						tmp[i] = _start[i];
					}
				}
				delete[] _start;
				_start = tmp;
				_finish = _start + size;
				_endofshort = _start + n;
			}
		}

		void PushBack(const T& value)
		{
			Insert(end(), value);
		}

		void PopBack()
		{
			Earse(end()-1);
		}

		Iterator Find(const T& value)
		{
			Iterator it = begin();
			while (it != end())
			{
				if (*it == value)
				{
					return it;
				}
				++it;
			}
		}

		Iterator Insert(Iterator pos, const T& value)
		{
			assert(pos <= _finish);
			//判断是否增容
			if (_finish == _endofshort)
			{
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newcapacity);
				//防止迭代器失效
				pos = _start + size;
			}
			//finish只得是下一个
			Iterator end = _finish - 1 ;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = value;
			++_finish;
			return pos;
		}


		Iterator Earse(Iterator pos)
		{
			assert(pos < _finish);
			Iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
		void Swap(Vector<T>& x)
		{
			swap(_start, x._start);
			swap(_finish, x._finish);
			swap(_endofshort, x._endofshort);
		}



		Vector<T>& operator = (Vector<T> x)
		{
			Swap(x);
			return *this;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return *(_start + pos);
		}
	private:
		T* _start;
		T* _finish;
		T* _endofshort;
	};
}








#endif