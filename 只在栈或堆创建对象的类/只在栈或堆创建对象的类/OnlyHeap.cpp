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
	//���캯����
	// 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
	// 2.������˽��
	

	//��ֹ����
	HeapType(const HeapType& ht);
	

};

//HeapType obj2;//��������Ϊ���캯��˽��
//HeapType::HeapType(const HeapType& ht)//��������Ҳ����
//{}
//
//int main()
//{
//	HeapType* p1 = HeapType::GetHeapObj();
//	/*HeapType obj1;*///������
//	/*HeapType obj3(*p1);*///������
//	system("pause");
//	return 0;
//}