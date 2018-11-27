#include <cstddef>
#include <iostream>
using namespace std;

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable
{
	ValueHolder(const T & val) : data_(val) {};
	ValueHolder* clone() const { return new ValueHolder(*this); }
	T data_;
};

int main()
{
	ValueHolder<string> val1("Hello!");
	cout << val1.data_ << endl;

	ValueHolder<string> * val2 = val1.clone();
	cout << val2->data_ << endl;

	return 0;
}

