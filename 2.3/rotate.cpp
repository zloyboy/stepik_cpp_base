#include <iostream>
using namespace std;

#define MY_SIZE	10

void rotate(int a[], unsigned size, int shift)
{
	int min_shift = shift % size;
	for(int i=0; i<min_shift; i++)
	{
		int first = a[0];
		for(int j=0; j<size; j++) a[j] = a[j+1];
		a[size-1] = first;
	}
}

int main()
{
    int m[MY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	rotate(m, MY_SIZE, 0);

	for(int i=0; i<MY_SIZE; i++) cout << " " << m[i];
	cout << endl;
	return 0;
}
