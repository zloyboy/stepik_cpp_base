#include <iostream>
using namespace std;

int main()
{
    bool space = false;
    char c = '\0';
    while (cin.get(c))
	{
        if (c==' ')
		{
			space = true;
		}
		else
		{
			if (space)
			{
				space = false;
				cout << ' ';
			}
			cout << c;
		}
    }
	return 0;
}
