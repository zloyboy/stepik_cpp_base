#include <time.h>
#include <cstring>
#include <iostream>
using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int idxMinRow = 0;
	int valMinRow = m[0][0];
	for(int i=0; i<rows; i++)
	{
		int valMin = m[i][0];
		for(int j=1; j<cols; j++)
			if (m[i][j] < valMin) valMin = m[i][j];
		if (valMin < valMinRow)
		{
			idxMinRow = i;
			valMinRow = valMin;
		}
	}
	if (idxMinRow)
	{
		int* tmp = m[0];
		m[0] = m[idxMinRow];
		m[idxMinRow] = tmp;
	}
}

int main()
{
	const int a = 10; 
	const int b = 5;
	srand (time(NULL));
	cout << "M:" << endl;
	int ** M = new int*[a];
	for(int i=0; i<a; i++)
	{
		M[i] = new int[b];
		for(int j=0; j<b; j++)
		{
			M[i][j] = rand() % 100;
			cout << " " << M[i][j];
		}
		cout << endl;
	}
	
	swap_min(M, a, b);
	cout << "M:" << endl;
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++) cout << " " << M[i][j];
		cout << endl;
	}

	return 0;
}
