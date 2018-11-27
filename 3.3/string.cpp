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

	String str1("Hello ");
	cout << str1.str << ":" << str1.size << endl;
	String str2("world!");
	str2 = str2;
	cout << str2.str << ":" << str2.size << endl;

	return 0;
}

/*char *resize(const char *str, unsigned size, unsigned new_size)
{
	char* ptr = new char[new_size];
	int copy_size = size;
	if (new_size < size ) copy_size = new_size;
	while (copy_size--) ptr[copy_size] = str[copy_size];
	delete [] str;
	return ptr;
}*/

/*char *getline()
{
	int capacity = 4;
	int len = 0;
	char* str = new char[capacity + 1];
    char c = 0;
    while (std::cin.get(c) && (c != '\n'))
	{
		if (len < capacity)
		{
			str[len++] = c;
		}
		else
		{
			capacity *= 2;
			char* str_temp = new char[capacity + 1];
			int copy_size = len;
			while (copy_size--) str_temp[copy_size] = str[copy_size];
			delete [] str;
			str = str_temp;
			str[len++] = c;
		}
    }
	str[len] = 0;
	return str;
}*/

