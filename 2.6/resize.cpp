#include <cstring>
#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char* ptr = new char[new_size];
	int copy_size = size;
	if (new_size < size ) copy_size = new_size;
	while (copy_size--) ptr[copy_size] = str[copy_size];
	delete [] str;
	return ptr;
}


int main()
{
	char* a1 = new char[11];
	strcpy( a1, "0123456789");
	cout << a1 << endl;

	char* a2 = resize(a1, 0, 0);
	cout << a2 << endl;

	delete [] a2;

	return 0;
}
