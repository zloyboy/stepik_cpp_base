#include "visitor2.hpp"

void Number::visit(Visitor * visitor) const { visitor->visitNumber(this); }
void BinaryOperation::visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

int main()
{
	Expression * sube1 = new BinaryOperation(new Number(9.2), '-', new Number(4.1));
	Expression * sube2 = new BinaryOperation(new Number(2.1), '+', new Number(3.2));
	Expression * expr1 = new BinaryOperation(sube1, '*', sube2);
	//Expression * expr2 = new BinaryOperation(sube1, '/', sube2);
	cout << expr1->evaluate() << endl;
	//cout << expr2->evaluate() << endl;

	PrintBinaryOperationsVisitor visitor;
	expr1->visit(&visitor);

	delete expr1;
	//delete expr2;

	return 0;
}

