#include"List.h"
#include<vector>



void test1()
{
	TJ::List<int> list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PushBack(5);
	list1.PopFront();
	TJ::List<int>::Iterator pos = list1.Find(2);
	list1.Insert(pos, 9);
	TJ::List<int>::Iterator it = list1.begin();
	TJ::List<int>::Iterator pos1 = list1.Find(4);
	list1.Erase(pos1);
	while (it != list1.end())
	{
		cout << *it << endl;
		++it;
	}
}







void test0()
{
	TJ::List<int> list1;
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	TJ::List<int>::Iterator it = list1.begin();
	while (it != list1.end())
	{
		cout << *it << endl;
		++it;
	}

	

	//迭代器区间构造
	TJ::List<int> list4(list1.begin(), list1.end());
	TJ::List<int>::Iterator it4 = list4.begin();
	while (it4 != list4.end())
	{
		cout << *it4 << endl;
		++it4;
	}

	//拷贝测试
	TJ::List<int> list2(list1);
	TJ::List<int>::Iterator it2 = list2.begin();
	while (it2 != list2.end())
	{
		cout << *it2 << endl;
		++it2;
	}

}





void test2()
{
	TJ::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(4);
	l.PushBack(4);
	cout << l.Size() << endl;
	cout << l.Empty() << endl;
	l.Resize(9,1);
	TJ::List<int>::Iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << endl;
		++it;
	}
}

void test3()
{
	TJ::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	TJ::List<int>::Iterator it = l.begin();
	++it;
	cout << *(it++) << endl;
	cout << *(it--) << endl;
}
int main()
{
	test0();
	system("pause");
	return 0;
}