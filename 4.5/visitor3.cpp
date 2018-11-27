#include <iostream>
using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void print() const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value) : value(value) {}
    double evaluate() const {return value;}
    void print() const { cout << value; }
private:
    double value;
};

struct BinaryOperation : Expression
{
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

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void print() const
	{
		cout << "(";
        get_left()->print();
        cout << " " << get_op() << " ";
        get_right()->print();
		cout << ")";
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



int main()
{
	//Expression * sube1 = new BinaryOperation(new Number(9.2), '-', new Number(4.1));
	Expression * sube1 = new BinaryOperation(new Number(3), '*', new Number(2));
	Expression * sube11 = new BinaryOperation(new Number(16), '-', sube1);

	//Expression * sube2 = new BinaryOperation(new Number(2.1), '+', new Number(3.2));
	Expression * sube2 = new BinaryOperation(new Number(10), '/', new Number(2));
	Expression * sube21 = new BinaryOperation(new Number(5), '+', sube2);

	//Expression * expr = new BinaryOperation(sube1, '*', sube2);
	Expression * expr = new BinaryOperation(sube11, '/', sube21);

	expr->print();
	cout << endl << expr->evaluate() << endl;


	delete expr;

	return 0;
}

