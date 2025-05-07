#include<iostream>
using namespace std;
class String
{
	String(const char* str="")
	{
		if (str == nullptr)
			return;
		_str = new char[sizeof(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
	{
		_str = new char[sizeof(s._str) + 1];
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str =new char[sizeof(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	~String()
	{
		if (_str != nullptr)
			delete[] _str;
	}
private:
	char* _str;
};