#include "Date.h"

void test1()
{
	Date d1(2017, 10, 10);
	Date d2(2017, 10, 21);
	cout << d1 - d2 << endl;
}



int main()
{
	test1();
	system("pause");
	return 0;
}