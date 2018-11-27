#include <iostream>
using namespace std;

//------------------------------------------------------------------
struct Foo
{
public:
	void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
	Foo(const char *msg) : msg(msg) { }
private:
	const char *msg;
};
void foo_says(const Foo &foo) { foo.say(); }
//------------------------------------------------------------------



//------------------------------------------------------------------
// memory leak
/*struct Fooo : Foo
{
	Fooo(const char *msg) : Foo(msg) { }
};
const Foo & get_foo(const char *msg)
{
	const Foo* foo = (Foo*)&msg;
	return *foo;
}*/
//------------------------------------------------------------------

struct Fooo : Foo
{
	Fooo(const char *msg) : Foo(msg) {}
};
const Foo get_foo(const char *msg)
{
	const Fooo fooo(msg);
	return fooo;
}

int main()
{ 
	foo_says(get_foo("Hello!"));

	return 0;
}

