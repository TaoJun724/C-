#include"String.h"

void TJ::String::Reserve(size_t n)
{
	if (n > _capacity)
	{
		char* newstr = new char[n + 1];
		strcpy(newstr, _str);
		delete[] _str;
		_str = newstr;
		_capacity = n;
	}
}

void TJ::String::Resize(size_t n, char ch)
{
	if (n <= _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		size_t pos = _size;
		while (pos < n)
		{
			_str[pos] = ch;
			++pos;
		}
		_size = n;
		_str[n] = '\0';
	}
}

void TJ::String::PushBack(char ch)
{
	if(_size == _capacity )
	{
	Reserve(_capacity = 0 ? 2 : _capacity*2);
	}
	_str[_size] = ch;

	_size++; 
	_str[_size] = '\0';
	/*Insert(_size, ch);*/

}

void TJ::String::Append(const char* str)
{
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
	Reserve(_size + len);
	}

	strcpy(_str + _size, str);
	_size += len;

	/*Insert(_size, str);*/
}

TJ::String& TJ::String::operator+=(char ch)
{
	this->PushBack(ch);
	return *this;
}

TJ::String& TJ::String::operator+=(const char* str)
{
	this->Append(str);
	return *this;
}

size_t TJ::String::Find(char ch, size_t pos)
{
	assert(pos < _size);

	while (pos < _size)
	{
		if (_str[pos] == ch)
		{
			return pos;
		}
		++pos;
	}
	return String::npos;
}

TJ::String TJ::String::Substr(size_t pos, size_t len)
{
	if (_size - pos < len)
	{
		len = _size - pos;
	}
	TJ::String sub;
	sub.Reserve(len);
	for (size_t i = pos; i < pos + len; ++i)
	{
		sub += _str[i];
	}
	return sub;
}

size_t TJ::String::RFind(char ch, size_t pos)
{
	int end = _size - 1;
	if (pos != String::npos)
	{
		assert(pos < _size);
		end = pos;
	}
	while (end > 0)
	{
		if (_str[end] == ch)
		{
			return end;
		}
		end--;
	}
	return String::npos;
}







size_t TJ::String::Find(const char* str, size_t pos)
{
	assert(pos < _size);
	char* substr = strstr(_str + pos, str);
	if (substr == nullptr)
	{
		return npos;
	}
	else
	{
		return substr - _str;
	}
}

void TJ::String::Insert(size_t pos, char ch)
{
	assert(pos <= _size);
	//增容
	if ((_size + 1) > _capacity)
	{
		Reserve(_capacity * 2);
	}
	int i = _size;
	for (; i >= (int)pos; i--)
	{
		_str[i + 1] = _str[i];
	}
	_str[pos] = ch;
	_size++;
}
void TJ::String::Insert(size_t pos, const char* str)
{
	assert(pos < _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		Reserve(_size + len);
	}

	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + len] = _str[end];
		--end;
	}

	while (*str)
	{
		_str[pos++] = *str++;
	}
	_size += len;
}
void TJ::String::Erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (len == npos || pos + len >= _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		for (size_t i = 0; i < len; ++i)
		{
			_str[pos] = _str[pos + len];
			pos++;
		}
		_size -= len;
		_str[_size] = '\0';
	}
}


ostream& TJ::operator<<(ostream& _cout, const String& s)
{
	_cout << s._str;
	return _cout;
}

void TestBitString1()
{
	TJ::String s1;
	TJ::String s2("hello bit");
	TJ::String s3(s2);
	s1 = s3;
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
void TestBitString2()
{
	TJ::String s1("hello");
	/*s1.PushBack(' ');
	s1.PushBack('b');*/
	s1.Append("jj");
	//s1 += 't';
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;



	 //利用迭代器打印string中的元素
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it++;
	}
	cout << endl;

	TJ::String s2("hello world!!!");
	s1.Swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;
}

void TestBitString3()
{
	TJ::String s("hellhhhhhhhhhhhhhhhhhhhhhhhhho");
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(10);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(15);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(20,'a');
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Reserve(50);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
}
int main()
{
	TestBitString2();
	system("pause");
}