#include<stdlib.h>
#pragma once


#include<iostream>

using namespace std;



class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	/*Date(const Date& d);	*/
	//~Date()//��������
	//{
	//  cout<<"~Date()"<<endl;
	//}



	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator+=(int days);
	Date operator-(int days);
	Date operator-=(int days);
	int operator-(const Date& d);
	Date& operator++();// ǰ��++����ʾ��d.operator++(&d)
	Date operator++(int);//����++����ʾ:d.operator(&d,0)
	Date& operator--();
	Date operator--(int);





	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	int GetMonthDay(int year, int month);
	void Print()const;
private:
	int _year;
	int _month;
	int _day;


};





