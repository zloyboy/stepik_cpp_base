#include <iostream>
using namespace std;

int main()
{
	const int a = 2;
	const int b = 3;
	srand (time(NULL));
	cout << "M1:" << endl;
	int **M = new int*[a];
	for(int i=0; i<a; i++)
	{
		M[i] = new int[b];
		for(int j=0; j<b; j++)
		{
			//M[i][j] = rand() % 100;
			M[i][j] = i*b + j + 1;
			cout << " " << M[i][j];
		}
		cout << endl;
	}

	//int **m = M;
	const int * const * m = M;
	//m[0][0] = 0;
	//m[1][1] = 0;
	const int * p = m[0];
	int * pp = p;
	//p[0] = 0;
	
	cout << "M2:" << endl;
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++) cout << " " << M[i][j];
		cout << endl;
	}

	return 0;
}

/*struct Cls
{
	Cls(char cc, double dd, int ii) : c(cc), d(dd), i(ii) {}
	void print() {cout << c <<" "<< d <<" "<< i << endl; }
private:
	char c;
	double d;
	int i;
};

char* get_ptr(Cls &cls)
{
	return (char*)&cls;
}

char &get_c(Cls &cls)
{
	return *get_ptr(cls);
}

double &get_d(Cls &cls)
{
	return *(double*)&(get_ptr(cls)[8]);
}

int &get_i(Cls &cls)
{
	return *(int*)&(get_ptr(cls)[16]);
}

int main()
{
	Cls cls(' ', 1.23, 56);
	cls.print();

	char& cc = get_c(cls);
	cout << cc << endl;
	cc = 'b';
	cls.print();

	double& dd = get_d(cls);
	cout << dd << endl;
	dd = 2.73;
	cls.print();

	int& ii = get_i(cls);
	cout << ii << endl;
	ii = 84;
	cls.print();

	return 0;
}*/

