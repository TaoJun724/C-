#include"Vector.h"



void test1()
{
	TJ::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(2);
	v.PushBack(1);
	v.PopBack();
	TJ::Vector<int>::Iterator pos = v.Find(3);
	v.Earse(pos);
	TJ::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
}

void test2()
{
	TJ::Vector<int> v(5, 10);
	TJ::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
	
}
void test3()
{
	int arr[] = { 12, 13, 47 };
	TJ::Vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	TJ::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << v.Size()<<endl;

	TJ::Vector<int> v3;
	v3 = v;
	TJ::Vector<int>::Iterator it3 = v3.begin();
	while (it3!= v3.end())
	{
		cout << *it3 << endl;
		++it3;
	}

	TJ::Vector<int> v2(v);
	TJ::Vector<int>::Iterator it2 = v2.begin();
	while (it2 != v2.end())
	{
		cout << *it2 << endl;
		++it2;
	}
}


void test4()
{
	TJ::Vector<int> v(5, 10);
	v.Resize(3);
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
	v.Resize(10, 0);
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}
}
int main()
{
	test4();
	system("pause");
	return 0;
}