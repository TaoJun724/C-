#include<iostream>
#include<stdlib.h>
using namespace std;






class HeapType
{
public:
	static HeapType* GetHeapObj()
	{
		return new HeapType;
	}

private:
	HeapType()
	{}
	//构造函数：
	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
	// 2.声明成私有
	

	//防止拷贝
	HeapType(const HeapType& ht);
	

};

//HeapType obj2;//不可以因为构造函数私有
//HeapType::HeapType(const HeapType& ht)//拷贝函数也不行
//{}
//
//int main()
//{
//	HeapType* p1 = HeapType::GetHeapObj();
//	/*HeapType obj1;*///不可以
//	/*HeapType obj3(*p1);*///不可以
//	system("pause");
//	return 0;
//}