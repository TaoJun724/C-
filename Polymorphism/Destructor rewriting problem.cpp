//������������д����


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

// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ� ̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ������������� 


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