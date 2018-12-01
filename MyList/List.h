#ifndef __LIST_H__
#define __LIST_H__


#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

namespace TJ
{
	template <class T>
	struct ListNode
	{
		//匿名对象T
		ListNode(const T& data = T()) :_data(data), _next(nullptr), _prev(nullptr)
		{

		}
		T _data;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};

	template <class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef  ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Iterator;



		ListIterator(Node* node) :_node(node)
		{

		}

		ListIterator(const Iterator& i) :_node(i._node)
		{

		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		//前置++
		Iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//后置++
		Iterator operator++(int)
		{
			Iterator i(*this);
			_node = _node->_next;
			return i;
		}


		//前置--
		Iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		Iterator operator--(int)
		{
			Iterator i(*this);
			_node = _node->_prev;
			return i;
		}

		bool operator!=(const Iterator& i)
		{
			return _node != i._node;

		}

		bool operator==(const Iterator& i)
		{
			return _node == i._node;
		}
		Node* _node;
	};



	template<class T>
	class List
	{
		typedef ListNode<T> Node;

	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T*> Const_Iterator;
		//构造函数
		//构造空的list
		List() :_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}
		//构造的list中包含n个值为data的元素
		List(int n, const T& data = new T()) :_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; i++)
			{
				PushBack(data);
			}
		}
		///用[first, last)区间中的元素构造list
		template<class Iterator>
		List(Iterator first, Iterator last)
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				PushBack(*first);
				*first++;
			}
		}

		//拷贝构造函数
		List(List<T>& l) :_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;

			List<T> tmp(l.begin(), l.end());
			swap(_head, l._head);
		}






		//赋值运算符重载
		List<T>& operator=(List<T>& l)
		{
			if (this != &l)
			{
				List<T> tmp(l);
				swap(_head, l._head);
			}
			return *this;
		}

		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}

		void Clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				_head = cur->_next;
				delete cur;
				cur = _head;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		Iterator begin()
		{
			return Iterator(_head->_next);
		}
		Iterator end()
		{
			return Iterator(_head);
		}

		void PushBack(const T& data)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(data);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			Insert(end(), data);
		}

		void PopBack()
		{
			/*Node* del = _head->_prev;
			if (del != _head)
			{
			Node* tail = del->_prev;
			_head->_prev = tail;
			tail->_next = _head;
			delete del;
			del = nullptr;
			}*/

			Erase(--end());
		}

		void PushFront(const T& data)
		{
			/*Node* front = _head->_next;
			Node* newnode = new Node(data);
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = front;
			front->_prev = newnode;*/

			Insert(begin(), data);
		}
		void PopFront()
		{
			/*Node* second = _head->_next->_next;
			_head->_next = second;
			delete second->_prev;
			second->_prev = _head;*/

			Erase(begin());
		}
		void Insert(Iterator pos, const T& data)
		{
			Node* cur = pos._node;
			Node* pre = cur->_prev;
			Node* newnode = new Node(data);
			cur->_prev = newnode;
			newnode->_next = cur;
			newnode->_prev = pre;
			pre->_next = newnode;
		}
		void Erase(Iterator pos)
		{
			Node* del = pos._node;
			Node* next = del->_next;
			Node* pre = del->_prev;
			pre->_next = next;
			next->_prev = pre;
			delete del;
			del = nullptr;
		}

		T& Front()
		{
			return _head->_next->_data;
		}
		T& Back()
		{
			return _head->_prev->_data;
		}

		const T& Front()
		{
			return _head->_next->_data;
		}
		const T& Back()
		{
			return _head->_prev->_data;
		}

		Iterator Find(const T& data)
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				if (cur->_data == data)
				{
					return Iterator(cur);
				}
				cur = cur->_next;
			}
		}


		size_t Size() const//O(n)不要经常调用
		{
			size_t count = 0;
			Node* cur = _head->_next;
			while (cur != _head)
			{
				++count;
				cur = cur->_next;
			}
			return count;
		}

		bool Empty()
		{
			return _head->_next == _head;
		}
		void Resize(int newsize, const T& data = T())
		{
			int oldsize = Size();
			if (newsize < oldsize)
			{
				for (int i = 0; i < (oldsize - newsize); i++)
				{
					PopBack();
				}
			}
			else
			{
				for (int i = 0; i < (newsize - oldsize); i++)
				{
					PushBack(data);
				}
			}
		}



	private:
		Node* _head;
	};
}





#endif