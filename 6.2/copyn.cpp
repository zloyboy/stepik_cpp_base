#include <cstddef>
#include <iostream>
using namespace std;

template <typename T, typename U>
void copy_n(T* dest, U* src, size_t num)
{
	if (dest && src && num)
	{
		for (size_t i=0; i<num; i++) dest[i] = T(src[i]);
	}
}

int main()
{
	const size_t size = 5; 
	int src[size] = {1, 2, 3, 4, 5};
	double dst[size] = {};
	copy_n(dst, src, size);
	
	for(size_t i=0; i<size; i++) cout << " " << dst[i];	
	cout << endl;

	return 0;
}
