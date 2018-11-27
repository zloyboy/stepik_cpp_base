#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
	unsigned rem, c;
	if( a < b )
	{
		rem = b % a;
		c = a;
	}
	else
	{
		rem = a % b;
		c = b;
	}
	if (rem) return gcd(rem, c);
	else return c;
}

int count = 0;
int foo(int n)
{
	cout << ++count << endl;
    if (n <= 0) return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

int main()
{
	unsigned a = 2034;
	unsigned b = 3456;
	cout << a << " " << b << " gcd: " << gcd(a, b) << endl;

	foo(3);

	return 0;
}

