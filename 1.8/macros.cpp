#include <iostream>
using namespace std;

//#define MAX(x, y, r)  if (((r) = (x)) < (y)) {(r) = (y);}	// Postfix decrement test failed
//#define MAX(x, y, r) {r = ((x) < (y)) ? (y) : (x); }		// Postfix decrement test failed
#define MAX(x, y, r)  { int xx = (x); int yy = (y); (r)=(xx < yy) ? (yy) : (xx); }

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	cout << "a:" << a << ", b:" << b << ", c:" << c << endl;

	//MAX(a, b, c);
	//MAX(a += b, b, c);
	MAX(a, b, c++);
	cout << "a:" << a << ", b:" << b << ", c:" << c << endl;

	return 0;
}

