#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	static const char monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 29;
	}
	return monthday[month];
}

Date::Date(int year, int month, int day)
{
	if ((year >= 0) && (month > 0) && (month < 13) && (day > 0) && (day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "输入的日期有误" << endl;
	}
}

//Date::Date(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}//系统会自动生成



bool Date:: operator>(const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._year)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

bool Date:: operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator<(const Date& d)const
{
	return !((*this > d)||(*this == d));
}

bool Date::operator>=(const Date& d)const
{
	return !(*this < d);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}



void Date::Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}







Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}
// 前置++，表示：d.operator++(&d)
Date& Date::operator++()
{

	this->_day++;
	while (this->_day > GetMonthDay(this->_year, this->_month))
	{
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month>12)
		{
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}
//后置++，表示:d.operator(&d,0)
Date Date::operator++(int)
{
	Date ret(*this);
	ret._day += 1;
	return *this;
}
Date& Date::operator--()
{
	this->_day--;
	while (this->_day <= 0)
	{
		this->_month--;
		if (this->_month == 0)
		{
			this->_year--;
			this->_month = 12;
		}
		else
		{
			--this->_month;
		}
		this->_day += GetMonthDay(this->_year, this->_day);
	}
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	ret._day -= 1;
	return *this;
}









Date Date::operator+(int days)
{
	Date ret(*this);
	ret._day += days;
	return *this;
}
Date Date::operator+=(int days)
{
	if (days < 0)
	{
		return *this -= (-days);
	}
	this->_day += days;
	while (this->_day > GetMonthDay(this->_year, this->_month))
	{
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month>12)
		{
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}
Date Date::operator-(int days)
{
	Date ret(*this);
	ret._day -= days;
	return *this;
}
Date Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this += (-days);
	}
	this->_day -= days;
	while (this->_day <= 0)
	{
		if (this->_month == 1)
		{
			this->_year--;
			this->_month = 12;
		}
		else
		{
			this->_month--;
		}
		this->_day += GetMonthDay(this->_year, this->_month);
	}
	return *this;
}



int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min < max)
	{
		++min;
		++n;
	}
	return n*flag;
}
