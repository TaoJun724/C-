#include<iostream>
using namespace std;


//c++98�н����캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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

//c++11�����ؼ���final��ֹ�̳�
class F final
{};