#include<iostream>
using namespace std;

class StackType
{
public:
	static StackType GetStackObj()
	{
		//return StackType();
		StackType obj;
		return obj;
	}

	void Print()
	{
		cout << "StackType::Print()" <<this<< endl;
	}
private:
	StackType()
	{}
};

//StackType obj;//不可以

int main()
{
	StackType::GetStackObj().Print();
	StackType obj = StackType::GetStackObj();
	obj.Print();

	/*StackType* p = new StackType;*///不可以
	return 0;
}
