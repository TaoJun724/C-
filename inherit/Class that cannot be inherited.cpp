#include<iostream>
using namespace std;


//c++98中将构造函数私有化，派生类中掉不到基类的构造函数，则无法继承
class Father
{
public:
	static Father GetInstance()
	{
		return Father();
	}
private:
	Father()
	{}
};

//c++11给出关键字final禁止继承
class F final
{};