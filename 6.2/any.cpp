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

// Это класс, который вам нужно реализовать
class Any
{
	ICloneable* held_;
public:
    // В классе Any должен быть конструктор,
    // который можно вызвать без параметров,
    // чтобы работал следующий код:
    //    Any empty; // empty ничего не хранит
	Any() : held_(0) {};

    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
	template<typename T>
	Any(const T& val) : held_(new ValueHolder<T>(val)) {}

    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
	~Any() { if (held_) delete held_; }

    // В классе Any также должен быть конструктор
    // копирования (вам поможет метод clone
    // интерфейса ICloneable)
	Any(const Any& any)
 	{
		if (any.held_) held_ = any.held_->clone();
		else held_ = 0;
	}

    // В классе должен быть оператор присваивания и/или
    // шаблонный оператор присваивания, чтобы работал
    // следующий код:
    //    Any copy(i); // copy хранит 10, как и i
    //    empty = copy; // empty хранит 10, как и copy
    //    empty = 0; // а теперь empty хранит 0
	Any & operator=(const Any & any)
	{
		if (&any != this)
		{
			if (held_) delete held_;
			if (any.held_) held_ = any.held_->clone();
			else held_ = 0;
		}
		return *this;
	}

    // Ну и наконец, мы хотим уметь получать хранимое
    // значение, для этого определите в классе Any
    // шаблонный метод cast, который возвращает
    // указатель на хранимое значение, или нулевой
    // указатель в случае несоответствия типов или
    // если объект Any ничего не хранит:
    //    int *iptr = i.cast<int>(); // *iptr == 10
    //    char *cptr = i.cast<char>(); // cptr == 0,
    //        // потому что i хранит int, а не char
    //    Any empty2;
    //    int *p = empty2.cast<int>(); // p == 0
    // При реализации используйте оператор dynamic_cast.
	template<typename T>
    T* cast() const
	{
		ValueHolder<T>* vheld = dynamic_cast< ValueHolder<T>* >(held_);
		if (vheld) return &vheld->data_;
		else return 0;
	}

    // Допустим у вас есть два наследника класса Base: Derived1 
    // и Derived2. Кроме того у вас есть указать baseptr
    // типа Base*. Как проверить указывает ли этот указатель на
    // самом деле на объект класса Derived1 или на объект 
    // класса Derived2? Для этого можно воспользоваться dynamic_cast-ом:
    //
    // Derived1 *derived1ptr = dynamic_cast<Derived1*>(baseptr);
    //
    // Если derived1ptr не равен 0, то  baseptr на самом деле
    // указывал на объект класса Derived1, если же derivedptr равен 0,
    // то baseptr на самом деле указывал на объкт какого-то другого 
    // класса (например, Derived2). Это можно проверить так:
    //
    // Derived2 *derived2ptr = dynamic_cast<Derived2*>(baseptr);
    //
    // dynamic_cast работает только, если в классе есть хотя бы
    // один виртуальный метод, и в шаблоне ValueHolder такой
    // как раз имеется.
};



/*void test0()
{
	struct X
	{
		ICloneable *p;
	};
	cout << endl << "***** Empty ***" << " (" << __FUNCTION__ << ")" << endl;
	Any aEmpty(NULL);
	cout << *aEmpty.cast<int>() << endl;
	Any bEmpty;
	if (((X*)&bEmpty)->p == NULL) {
		cout << "Empty: OK";
	}
	else
	{
		cout << "Empty: Failed" << endl;
	}
	cout << endl;
	if (bEmpty.cast<string>()) { cout << *bEmpty.cast<string>() << endl; }
	Any  cEmpty;
	bEmpty = cEmpty;
	cout << "Address: " << &bEmpty << " Pointer value: " << (((X*)&bEmpty)->p) << endl;
}*/

void test1()
{
	cout << endl << "***** INT (Self = Self ) ***" << " (" << __FUNCTION__ << ")" << endl;
	int INT = 1;
	Any aINT(INT);
	cout << *aINT.cast<int>() << " == " << INT << endl;
	aINT = aINT;
	cout << *aINT.cast<int>() << " == " << INT << endl;
}

void test2()
{
	cout << endl << "***** INT (Copy ) ***" << " (" << __FUNCTION__ << ")" << endl;
	int INT = 2;
	Any aINT(INT);
	cout << *aINT.cast<int>() << " == " << INT << endl;;
	Any nEmpy(aINT);
	cout << *nEmpy.cast<int>() << " == " << INT << endl;
}

void test3()
{
	cout << endl << "***** INT (Empty, =, copy, cast) ***" << " (" << __FUNCTION__ << ")" << endl;
	int INT = 10;
	{
		Any aINT(INT);
		cout << *aINT.cast<int>() << " == " << INT ;
	}
	cout << endl;
	{
		Any aINT(INT);
		Any aEmpty;
		aEmpty = aINT;
		int tmp = *aEmpty.cast<int>();
		cout << tmp << " == " << INT ;
	}
	cout << endl;
	{
		Any aINT(INT);
		Any aEmpty;
		aEmpty = aINT;
		aEmpty = aEmpty;
		cout << *aEmpty.cast<int>() << " == " << INT ;
	}
	cout << endl;
	{
		Any aEmpty;
		aEmpty = 0;
		cout << *aEmpty.cast<int>() << " == " << 0 ;
	}
	cout << endl;
	{
		struct X
		{
			ICloneable *p;
		};
		Any aEmpty;
		Any bEmpty(aEmpty);
		if (((X*)&bEmpty)->p == NULL) {
			cout << "Empty: OK";
		}
		else
		{
			cout << "Empty: Failed" << endl;
		}
	}
	cout << endl;
	return;
}

void test4()
{
	string  STR("Hello!");
	cout << endl << "***** STRING (empty, =, copy, cast) ***" << " (" << __FUNCTION__ << ")" << endl;
	{

		Any aINT(STR);
		cout << *aINT.cast<string>() << " == " << STR ;
	}
	cout << endl;
	{
		Any aINT(STR);
		Any aEmpty;
		aEmpty = aINT;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
	}
	cout << endl;
	{
		string sEmpty("");
		Any aEmpty(sEmpty);
		aEmpty = aEmpty;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
		aEmpty = aEmpty;
		cout << *aEmpty.cast<string>() << " == " << STR << endl;
		Any nEmpty(aEmpty);
		cout << *nEmpty.cast<string>() << " == " << STR << endl;
	}
	cout << endl;
	{
		int i = 10;
		ValueHolder<int>* intHolder = new ValueHolder<int>(i);
		ValueHolder<char>* charHolder = dynamic_cast<ValueHolder<char>*>(intHolder->clone());
		ValueHolder<int>* int2Holder = dynamic_cast<ValueHolder<int>*>(intHolder->clone());
		cout << "Char* 4 Int* " << (charHolder ? "Cast: OK" : "Cast: Failed") << endl;
		cout << "Int* 4 Int*" << (int2Holder ? "Cast: OK" : "Cast: Failed") ;
		delete intHolder;
		delete charHolder;
		delete int2Holder;
	}
	cout << endl;
}

void test5()
{
	cout << endl << "*** INT, DOUBLE, STRING ***" << " (" << __FUNCTION__ << ")" << endl;
	string Hello = "Hello World People";
	ValueHolder<int> Int(10);
	ValueHolder<string> Str(Hello);
	double Dbl = 10.112233;

	Any aHello(Hello);
	Any aInt(Int);
	Any aStr(Str);
	Any aDbl(Dbl);

	cout << aHello.cast<string>()->data() << " == " << Hello.data() << endl;
	cout << aInt.cast<ValueHolder<int> >()->data_ << " == " << Int.data_ << endl;
	cout << aStr.cast<ValueHolder<string> >()->data_.data() << " == " << Hello.data() << endl;
	cout << *aDbl.cast<double>() << " == " << Dbl << endl;

	aHello = (char*)"Any other simple text";
	aInt = 10241;
	aDbl = 234.5675;

	cout << *aHello.cast<char *>() << " == " << "Any other simple text" << endl;
	cout << *aInt.cast<int>() << " == " << 10241 << endl;
	cout << *aDbl.cast<double>() << " == " << 234.5675 << endl;
}

void test6()
{
	// Memory leak!!!
	cout << endl << "*** Array (= new Any(i))***" << " (" << __FUNCTION__ << ")" << endl;
	int n = 5;
	{
		Any *pAny = new Any[n];
		for (int i = 0; i < n; i++)
			pAny[i] = new Any(i*i + 1);

		for (int i = 0; i < n; i++)
			cout << "\tpAny[" << i << "] = " << *(*pAny[i].cast<Any*>())->cast<int>() << " == " << i*i + 1 << endl;
		delete[] pAny;
	}
	cout << endl;
}

void test7()
{
	cout << endl << "*** Array (= Any(i))***" << " (" << __FUNCTION__ << ")" << endl;
	const int n = 30;
	Any pAny2[n];

	for (int i = 0; i < n; i++)
		pAny2[i] = Any(i + 1);

	for (int i = 0; i < n; i++)
		cout << "\tpAny2[" << i << "] = " << *pAny2[i].cast<int>() << " == " << i + 1 << endl;
}

int main()
{
	//test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}

