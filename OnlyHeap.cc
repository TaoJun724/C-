#include<iostream>
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


int main()
{
	HeapType* p1 = HeapType::GetHeapObj();
	/*HeapType obj1;*///不可以
	/*HeapType obj3(*p1);*///不可以
	return 0;
}

