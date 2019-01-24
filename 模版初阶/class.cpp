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


	// 在类中声明，在类外定义
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
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
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