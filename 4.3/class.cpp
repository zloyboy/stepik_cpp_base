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
bool check_equals(Expression const *left, Expression const *right)
{
    unsigned* vptr1 =  *(unsigned**)left;
    unsigned* vptr2 =  *(unsigned**)right;
	return (vptr1 == vptr2);
}
//------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------
int main()
{
	Expression * sube1 = new BinaryOperation(new Number(9.2), '-', new Number(4.1));
	Expression * sube2 = new BinaryOperation(new Number(2.1), '+', new Number(3.2));

	Expression * expr1 = new BinaryOperation(sube1, '*', sube2);
	cout << expr1->evaluate() << endl;
	delete expr1;
	
	/*Expression * expr2 = new BinaryOperation(sube1, '/', sube2);
	cout << expr2->evaluate() << endl;
	delete expr2;*/

	// sizeof
	/*cout << sizeof(Expression) << endl;
	cout << sizeof(Number) << endl;
	cout << sizeof(BinaryOperation) << endl;*/
	
	// check_equals
	/*Expression * num1 = new Number(1.2);
	Expression * num2 = new Number(3.4);
	Expression * num3 = new Number(5.6);
	Expression * num4 = new Number(7.8);
	Expression * exp1 = new BinaryOperation(num1, '-', num2);
	Expression * exp2 = new BinaryOperation(num3, '+', num4);
	cout << check_equals(num1, num2) << endl;
	cout << check_equals(exp1, exp2) << endl;
	cout << check_equals(num3, exp2) << endl;
	cout << check_equals(exp1, num4) << endl;
	delete exp1;
	delete exp2;*/

	return 0;
}

