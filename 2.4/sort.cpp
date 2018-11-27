#include <iostream>
#include <algorithm>
using namespace std;

#define MY_SIZE	10


int main()
{
    int m[MY_SIZE] = {10, 7, 3, 9, 5, 8, 1, 2, 4, 6};
	
	int *minptr = min_element(m, m + MY_SIZE);
	int *maxptr = max_element(m, m + MY_SIZE);
	cout << "min: " << *minptr << endl;
	cout << "max: " << *maxptr << endl;	

	sort(m, m + MY_SIZE);	
	for(int i=0; i<MY_SIZE; i++) cout << " " << m[i];
	cout << endl;

	return 0;
}
