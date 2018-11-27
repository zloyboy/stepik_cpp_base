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
	~String() { delete [] str; }

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

	void append(const String &other)
	{
		char* str_temp = new char[size + other.size + 1];
		strcpy(str_temp, str);
		strcpy(&str_temp[size], other.str);
		delete [] str;
		str = str_temp;
		size += other.size;
	}

	//char & at(size_t idx)       { return str[idx]; }
    //char   at(size_t idx) const { return str[idx+1]; }

	struct SubStr
	{
        SubStr(size_t sz, const char *src = "", int idx = 0) : subsize(sz), substr(new char[subsize + 1]), startIdx(idx)
		{
			char* str = substr;
			while(*str++ = *src++);
		}

        const char* operator[](int idx) const
		{
			substr[idx] = 0;
            return &substr[startIdx];
        }

		~SubStr() { delete [] substr; }
		
		size_t subsize;
        char *substr;
		int startIdx;
    };
	SubStr operator[](int idx) const { return SubStr(size, str, idx); }

	size_t size;
	char *str;
};


#include <iostream>
using namespace std;

int main()
{
	String hello("Hello, world!!!");

	String str = hello[0][4];
	str.append(hello[5][12]);
	cout << str.str << endl;

	String const str1 = hello[0][4];
	cout << str1.str << endl;

	String const str2  = hello[5][12];
	cout << str2.str << endl;

	return 0;
}

