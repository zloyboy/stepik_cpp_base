#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor
{
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value) : value(value) {}
    double evaluate() const {return value;}
    double get_value() const { return value; }
    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
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

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

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




struct PrintVisitor : Visitor
{
    void visitNumber(Number const * number)
    {
		std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
		std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op();
        bop->get_right()->visit(this);
		std::cout << ")";
    }
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

	std::cout << expr->evaluate() << std::endl;

	PrintVisitor printVisitor;
	expr->visit(&printVisitor);

	delete expr;

	return 0;
}

