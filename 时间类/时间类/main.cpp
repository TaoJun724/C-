#include "Date.h"

void test1()
{
	Date d1(2017, 10, 27);
	Date d2(2017, 10, 21);
	++d1;
	d1.Print();
}



int main()
{
	test1();
	system("pause");
	return 0;
}