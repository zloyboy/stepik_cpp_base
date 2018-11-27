#include <iostream>
using namespace std;

//------------------------------------------------------------------------------------------
// Expression
//------------------------------------------------------------------------------------------
struct Expression
{
    virtual double evaluate() const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value) : value(value) {}
	double evaluate() const {return value;}
private:
    double value;
};

struct BinaryOperation : Expression
{
	// Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям, которые вам нужно реализовать.
    BinaryOperation(Expression const * left, char op, Expression const * right) : left(left), op(op), right(right) { }

	double evaluate() const
	{
		switch(op)
		{
		case '+':
			return left->evaluate() + right->evaluate();
		break;

		case '-':
			return left->evaluate() - right->evaluate();
		break;

		case '*':
			return left->evaluate() * right->evaluate();
		break;

		case '/':
			return left->evaluate() / right->evaluate();
		break;

		default:
			return 0.0;
		}
	}

	~BinaryOperation()
	{
		delete left;
		delete right;
	}

private:
    Expression const * left;
    Expression const * right;
    char op;
};
//------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------
// ScopedPtr
//------------------------------------------------------------------------------------------
struct ScopedPtr
{
    explicit ScopedPtr(Expression *ptr = 0) : ptr_(ptr) {}
    ~ScopedPtr() { if (ptr_) delete ptr_; }
    Expression* get() const { return ptr_; }
    Expression* release()
	{
		Expression* ptr = ptr_;
		ptr_ = 0;
		return ptr;
	}
    void reset(Expression *ptr = 0)
	{
		if (ptr_) delete ptr_;
		ptr_ = ptr;
	}
    Expression& operator*() const { return *ptr_; }
    Expression* operator->() const { return ptr_; }

private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};
//------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------
int main()
{
	/*Expression * sube1 = new BinaryOperation(new Number(9.2), '-', new Number(4.1));
	Expression * sube2 = new BinaryOperation(new Number(2.1), '+', new Number(3.2));
	Expression * expr = new BinaryOperation(sube1, '*', sube2);
	cout << expr->evaluate() << endl;
	delete expr;*/

	{
		ScopedPtr ptr1( new BinaryOperation(new Number(9.2), '-', new Number(4.1)) );
		cout << ptr1->evaluate() << endl;
		ScopedPtr ptr2( new BinaryOperation(new Number(2.1), '+', new Number(3.2)) );
		cout << ptr2->evaluate() << endl;
		ScopedPtr ptr3( new BinaryOperation(ptr1.get(), '*', ptr2.get()) );
		cout << ptr3->evaluate() << endl;
	}
	cout << "exit" << endl;

	return 0;
}

