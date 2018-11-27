#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
	String(const char *str = "") : size(strlen(str)), str(new char[size + 1])
	{
		strcpy(this->str, str);
	}

	String(size_t n, char c) : size(n), str(new char[size + 1])
	{
		for(int i=0; i<size; i++) str[i] = c;
		str[size] = 0;
	}

	String(const String &other) : size(other.size), str(new char[size + 1])
	{
		for(int i=0; i<size; i++) str[i] = other.str[i];
		str[size] = 0;
	}

	String &operator=(const String &other)
	{
		if (&other != this)
		{
			delete [] str;
			size = other.size;
			str = new char[size + 1];
			for(int i=0; i<size; i++) str[i] = other.str[i];
			str[size] = 0;
		}
		return *this;
	}

	void append(String &other)
	{
		char* str_temp = new char[size + other.size + 1];
		strcpy(str_temp, str);
		strcpy(&str_temp[size], other.str);
		delete [] str;
		str = str_temp;
		size += other.size;
	}

	char & at(size_t idx)       { return str[idx]; }
    char   at(size_t idx) const { return str[idx+1]; }

	~String()
	{
		delete [] str;
	}

	size_t size;
	char *str;
};


#include <iostream>
using namespace std;

int main()
{
	//String str("qwertyuiop");
	//String str(0, 'q');
	
	/*String str1("Hello ");
	String str2("world!");
	str2.append(str2);
	cout << str2.str << ":" << str2.size << endl;*/

	/*String str1("Hello ");
	cout << str1.str << ":" << str1.size << endl;
	String str2("world!");
	str2 = str2;
	cout << str2.str << ":" << str2.size << endl;*/

	String greet("Hello");
	char ch1 = greet.at(0);
	cout << ch1 << endl;

	String const const_greet("Hello, Const!");
	char const &ch2 = const_greet.at(0);
	cout << ch2 << endl;

	return 0;
}

