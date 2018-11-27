#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(0)
	{
		if (size_)
		{
			data_ = new T[size_];
			for (size_t i=0; i<size_; i++) data_[i] = value;
		}
	}
	Array (const Array & a) : size_(a.size()), data_(0)
	{
		if (size_)
		{
			data_ = new T[size_];
			for (size_t i=0; i<size_; i++) data_[i] = a[i];
		}
	}
    ~Array()
	{
		if (data_) delete [] data_;
	}

	Array & operator=(const Array & a)
	{
		if (&a != this)
		{
			if (data_)
			{
				delete [] data_;
				data_ = 0;
			}
			size_ = a.size();
			if (size_)
			{
				data_ = new T[size_];
				for (size_t i=0; i<size_; i++) data_[i] = a[i];
			}
		}
		return *this;
	}

    size_t size() const { return size_; }

    T& operator[](size_t idx) { return data_[idx]; }
    const T& operator[](size_t idx) const { return data_[idx]; }

	void print()
	{
		cout << "data: ";
		for (size_t i=0; i<size_; i++) cout << data_[i] << " ";
		cout << endl;
	}

private:
	size_t size_;
	T* data_;
};

int main()
{
	//	test 1
	Array<int> a1(5, 1);
	a1.print();
	
	Array<float> a2(10, 1.1);
	a2.print();

	Array<int> a3(a1);
	a3.print();

	a1 = a3;
	a1.print();

	//	test 2
	/*Array<int> a1(0, 0);
	a1.print();

	Array<int> a2(a1);
	a2.print();
	a1 = a2;
	a1.print();*/

	cout << "exit" << endl;

	return 0;
}
