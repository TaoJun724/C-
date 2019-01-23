#include<iostream>
#include<stdlib.h>
using  namespace  std;





template<class T>
class Vector
{
public:
	Vector( )
		: _pData()
		, _size(0)
		, _capacity(10)
	{}


	// �����������������ⶨ��
	~Vector();

	void PushBack(const T& data)
	{
		// _CheckCapacity();
		_pData[_size++] = data;
	}	void PopBack()
	{
		--_size;
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
	{
		delete[] _pData;
	}
}

int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	system("pause");
	return 0;
}