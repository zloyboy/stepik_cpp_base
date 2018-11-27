#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	if (num < 0) return 0;
	int x = 0, y = 0;
	for (; num--;) {
		cin >> x >> y;
		cout << (x + y) << endl;
	}
	return 0;
}
