#include <iostream>
using namespace std;

void input()
{
	int num = 0;
    cin >> num;
    if (num)
	{
		input();
    	cout << num << " ";
	}
}

int main()
{
    input();
	return 0;
}
