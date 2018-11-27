#include <cstring>
#include <iostream>
using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	unsigned trows = cols;
	unsigned tcols = rows;
	int** mt = new int*[trows];
	int* t = new int[trows*tcols];
	for(int i=0; i<trows; i++) mt[i] = &t[i*tcols];
	for(int i=0; i<trows; i++)
		for(int j=0; j<tcols; j++)
	 		mt[i][j] = m[j][i];

	return mt;
}

int main()
{
	const int a = 10; 
	const int b = 15;
	cout << "M:" << endl;
	int ** M = new int*[a];
	for(int i=0; i<a; i++)
	{
		M[i] = new int[b];
		for(int j=0; j<b; j++)
		{
			M[i][j] = i*b + j + 1;
			cout << " " << M[i][j];
		}
		cout << endl;
	}		

	int** MT = transpose(M, a, b);
	cout << "MT:" << endl;
	for(int i=0; i<b; i++)
	{
		for(int j=0; j<a; j++) cout << " " << MT[i][j];
		cout << endl;
	}

	return 0;
}
