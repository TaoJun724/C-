#include<iostream>
#include<stdlib.h>
using namespace std;




//
//�Ƽ�����
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
//StackType obj;//������
//
//int main()
//{
//	StackType::GetStackObj().Print();
//	StackType obj = StackType::GetStackObj();
//	obj.Print();
//
//	/*StackType* p = new StackType;*///������
//	system("pause");
//	return 0;
//}



//���Ƽ��ķ�������Ӱ���Ķ����new����������Ѩ���������ݶ��� ;eg StackType obj2; main�е�static  StackOnly obj3;Ҳ���Զ��ϴ�����
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

StackType obj2;//���Դ������Բ��Ƽ�

int main()
{
	StackType obj1;//����
	static StackType obj3;//����
	//StackType* pobj2 = new StackType; // ֻ�����������


	system("pause");
	return 0;
}

