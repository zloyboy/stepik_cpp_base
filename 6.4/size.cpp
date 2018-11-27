#include <cstddef>
#include <iostream>
using namespace std;

template <class T, size_t N>
size_t array_size(T (&a)[N]) { return N; }

int main()
{
	int ints[] = {1, 2, 3, 4};
	int *iptr = ints;
	double doubles[] = {3.14};

	cout << array_size(ints) << endl;
	cout << array_size(doubles) << endl;
	array_size(iptr);

	return 0;
}
