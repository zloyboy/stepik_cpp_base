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
/*struct ScopedPtr
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
};*/
//------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------
// SharedPtr
//------------------------------------------------------------------------------------------
struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0) : ptr_(ptr), cnt_(0)
	{
		if (ptr_) cnt_ = new size_t (1);
	}
	SharedPtr(const SharedPtr& shared) : ptr_(shared.ptr_), cnt_(shared.cnt_)
	{
		if (cnt_) ++*cnt_;
	}
    SharedPtr& operator=(const SharedPtr& shared)
	{
		if (&shared != this)
		{
			if (cnt_ && (--*cnt_ == 0))
			{
				delete ptr_;
				delete cnt_;
				//cout << "del =" << endl;
			}
			ptr_ = shared.ptr_;
			cnt_ = shared.cnt_;
			if (cnt_) ++*cnt_;
		}
	}
    void reset(Expression *ptr = 0)
	{
		if (ptr != ptr_)
		{
			if (cnt_ && (--*cnt_ == 0))
			{
				delete ptr_;
				delete cnt_;
				//cout << "del res" << endl;
			}
			ptr_ = ptr;
			cnt_ = 0;
			if (ptr_) cnt_ = new size_t (1);
		}
	}
    ~SharedPtr()
	{
		if (cnt_ && (--*cnt_ == 0))
		{
			delete ptr_;
			delete cnt_;
			//cout << "delete" << endl;
		}
	}

    Expression* get() const { return ptr_; }
    Expression& operator*() const { return *ptr_; }
    Expression* operator->() const { return ptr_; }

private:

	size_t *cnt_;
    Expression *ptr_;
};
//------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------
int main()
{
	//	test 1
	/*SharedPtr ptr1( new BinaryOperation(new Number(1.1), '+', new Number(2.2)) );
	ptr1 = ptr1;
	cout << ptr1->evaluate() << endl;
	SharedPtr ptr2(ptr1);
	ptr2 = ptr1;
	cout << ptr2->evaluate() << endl;*/

	//	test 2
	/*SharedPtr ptr1(0);
	ptr1 = ptr1;
	SharedPtr ptr2(ptr1);
	ptr1.reset(0);
	ptr2.reset(0);
	ptr2 = ptr1;*/
	
	//	test 3
	/*SharedPtr ptr1( new BinaryOperation(new Number(1.1), '+', new Number(2.2)) );	
	ptr1 = ptr1;
	cout << ptr1->evaluate() << endl;
	SharedPtr ptr2( new BinaryOperation(new Number(3.3), '+', new Number(4.4)) );
	ptr2 = ptr2;
	cout << ptr2->evaluate() << endl;
	ptr2 = ptr1;
	cout << ptr2->evaluate() << endl;*/

	SharedPtr ptr1( new BinaryOperation(new Number(1.1), '+', new Number(2.2)) );
	cout << ptr1->evaluate() << endl;
	ptr1.reset(0);
	ptr1.reset( new BinaryOperation(new Number(3.3), '+', new Number(4.4)) );
	cout << ptr1->evaluate() << endl;
	ptr1.reset(0);

	cout << "exit" << endl;
	return 0;
}

