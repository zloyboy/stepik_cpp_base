#include <iostream>
using namespace std;

struct Visitor;

//------------------------------------------------------------------------------------------
// Expression
//------------------------------------------------------------------------------------------
struct Expression
{
    virtual double evaluate() const = 0;
	virtual void visit(Visitor * visitor) const  = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value) : value(value) {}
	double evaluate() const {return value;}
	double get_val() const { return value; }

	void visit(Visitor * visitor) const;
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

	Expression const * get_left()  const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

	void visit(Visitor * visitor) const;

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
// Visitor
//------------------------------------------------------------------------------------------
struct Visitor
{
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
    virtual ~Visitor() { }
};
struct PrintBinaryOperationsVisitor : Visitor
{
    void visitNumber(Number const * number)
	{
		cout << number->get_val();
	}

    void visitBinaryOperation(BinaryOperation const * bop)
    {
		cout << "(";
        bop->get_left()->visit(this);
        cout << " " << bop->get_op() << " ";
        bop->get_right()->visit(this);
		cout << ")";
    }
};
//------------------------------------------------------------------------------------------

