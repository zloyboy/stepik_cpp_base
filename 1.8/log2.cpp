#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	if (num < 0) return 0;
	int x = 0;
	for (; num--;)
	{
		cin >> x;
		int i;
		int base = 1;
		for(i=0; i<30; i++)
		{
			base <<= 1;
			if( x < base)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
