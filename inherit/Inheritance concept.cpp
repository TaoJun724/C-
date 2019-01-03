#include<iostream>
#include<stdlib.h>
#include<string>
using  namespace std;

class Person
{
public:
	void Print()
	{
		cout << "age " << age << endl;
		cout << "sex " << sex << endl;
	}
protected:
	int age = 20;
	string sex = "man";
};

class Student : public Person
{
protected:
	int stuid;//Ñ§ºÅ
};

class Teacher : public Person
{
protected:
};
