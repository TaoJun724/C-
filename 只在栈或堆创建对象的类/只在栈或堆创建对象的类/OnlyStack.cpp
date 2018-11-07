#include<iostream>
#include<stdlib.h>
using namespace std;




//
//推荐方法
//class StackType
//{
//public:
//	static StackType GetStackObj()
//	{
//		return StackType();
//		StackType obj;
//		return obj;
//	}
//
//	void Print()
//	{
//		cout << "StackType::Print()" <<this<< endl;
//	}
//private:
//	StackType()
//	{}
//};
//
//StackType obj;//不可以
//
//int main()
//{
//	StackType::GetStackObj().Print();
//	StackType obj = StackType::GetStackObj();
//	obj.Print();
//
//	/*StackType* p = new StackType;*///不可以
//	system("pause");
//	return 0;
//}



//不推荐的方法：不影响别的对象的new，但它有死穴，比如数据段中 ;eg StackType obj2; main中的static  StackOnly obj3;也可以堆上创建。
class StackType
{
public:
	StackType()
	{}

	void Print()
	{
		cout << "StackType::Print()" << endl;
	}

private:
	void* operator new(size_t n) = delete;
	void operator delete(void* p) = delete;
};

StackType obj2;//可以创建所以不推荐

int main()
{
	StackType obj1;//可以
	static StackType obj3;//可以
	//StackType* pobj2 = new StackType; // 只有这个不可以


	system("pause");
	return 0;
}

