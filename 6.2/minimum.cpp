#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
	explicit Array(size_t size, const T& value = T()) : size_(size), data_(0)
	{
		if (size_)
		{
			data_ = (T*) new char[size_*sizeof(T)];
			for (size_t i=0; i<size_; i++) new (&data_[i]) T(value);
		}
	}
	Array (const Array & a) : size_(a.size()), data_(0)
	{
		if (size_)
		{
			data_ = (T*) new char[size_*sizeof(T)];
			for (size_t i=0; i<size_; i++) new (&data_[i]) T(a[i]);
		}
	}
    ~Array()
	{
		if (data_)
		{
			for (size_t i=0; i<size_; i++) data_[i].~T();
			delete [] (char*) data_;
		}
	}
	Array & operator=(const Array & a)
	{
		if (&a != this)
		{
			if (data_)
			{
				for (size_t i=0; i<size_; i++) data_[i].~T();
				delete [] (char*) data_;
				data_ = 0;
			}
			size_ = a.size();
			if (size_)
			{
				data_ = (T*) new char[size_*sizeof(T)];
				for (size_t i=0; i<size_; i++) new (&data_[i]) T(a[i]);
			}
		}
		return *this;
	}

	//void swap(Array &other);

	size_t size() const { return size_; }
    T& operator[](size_t idx) { return data_[idx]; }
    const T& operator[](size_t idx) const { return data_[idx]; }

	void prnt()
	{
		cout << "data: ";
		for (size_t i=0; i<size_; i++) cout << data_[i] << " ";
		cout << endl;
	}

private:
	size_t size_;
	T *data_;
};

bool Less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };




template <class T, class Comp>
const T minimum(const Array<T> & array, Comp comp)
{
	T elem = array[0];
	for(size_t i=1; i < array.size(); i++)
		if (comp(array[i], elem)) elem = array[i];
	return elem;
}



int main()
{
	const size_t size = 3;

	Array<int> ints(size);
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	//ints.prnt();

	int min = minimum(ints, Less); // в min должно попасть число 2
	cout << "min:" << min << endl;
	
	int max = minimum(ints, Greater()); // в max должно попасть число 15
	cout << "max:" << max << endl;
	
	return 0;
}

