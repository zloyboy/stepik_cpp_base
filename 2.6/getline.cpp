#include <iostream>

char *getline()
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
}


int main()
{
	char* str = getline(); 
	std::cout << str << std::endl;
	delete [] str;

	return 0;
}

