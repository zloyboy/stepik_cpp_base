
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	double D = b*b - 4.0*a*c;
	if( 0 <= D )
	{
		double root1 = (-b - sqrt(D))/2.0/a;
		double root2 = (-b + sqrt(D))/2.0/a;
		cout << root1 << " " << root2 << endl;
	}
	else
	{
		cout << "No real roots" << endl;
	}
	return 0;
}
