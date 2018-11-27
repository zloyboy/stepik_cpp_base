#include <cstddef>
#include <iostream>
using namespace std;

template <class T1, class T2>
struct SameType
{ static const bool value = false; };

template <class T> struct
SameType<T, T>
{ static const bool value = true; };

int main()
{
	struct Dummy { };
	typedef int type;

	cout << SameType<int, int>::value << endl; // выведет 1, т. е. true
	cout << SameType<int, type>::value << endl; // 1, type == int
	cout << SameType<int, int&>::value << endl; // 0, int и ссылка на int - различные типы
	cout << SameType<Dummy, Dummy>::value << endl; // 1
	cout << SameType<int, const int>::value << endl; // 0, const - часть типа

	return 0;
}
