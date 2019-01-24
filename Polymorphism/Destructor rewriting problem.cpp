//析构函数的重写问题


#include<iostream>
#include<stdlib.h>
using namespace std;




class Father{
public:
	virtual ~Father()
	{
		cout << "~Father()" << endl;
	}
};



class Son : public Father
{
public:
	virtual ~Son()
	{
		cout << "~Son()" << endl;
	}
};

// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多 态，才能保证p1和p2指向的对象正确的调用析构函数。 


//int main()
//{
//	Father* p1 = new Father;
//	Father* p2 = new Son;
//
//	delete p1;
//	delete p2;
//
//
//	system("pause");
//	return 0;
//}