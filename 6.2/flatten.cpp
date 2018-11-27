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




template <typename T>
void flatten(const T & t, std::ostream& out) { out << " " << t; }

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) { for(size_t i=0; i<array.size(); i++) flatten(array[i], out); }




int main()
{
	Array<int> ints(3);
	ints[0] = 2;
	ints[1] = 10;
	ints[2] = 15;
	flatten(ints, std::cout);
	cout << endl;

	Array<float> floats(4);
	floats[0] = 1.2;
	floats[1] = 3.4;
	floats[2] = 5.6;
	floats[3] = 7.8;
	flatten(floats, std::cout);
	cout << endl;

	Array< Array<int> > array_of_ints(3, ints);
	flatten(array_of_ints, std::cout);
	cout << endl;

	return 0;
}

