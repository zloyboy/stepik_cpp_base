#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational)
 	{
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }
    void sub(Rational rational)
	{
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }
    void mul(Rational rational)
	{
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }
    void div(Rational rational)
	{
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }
    void neg()
	{
        numerator_ = -numerator_;
    }
    void inv() {}
    double to_double() const
	{
        return numerator_ / (double) denominator_;
    }

	operator double() const { return to_double(); }

	/*Rational& operator+=(const Rational & r)
	{
		this->add(r);
		return *this;
	}
	Rational& operator-=(const Rational & r)
	{
		this->sub(r);
		return *this;
	}
	Rational& operator*=(const Rational & r)
	{
		this->mul(r);
		return *this;
	}
	Rational& operator/=(const Rational & r)
	{
		this->div(r);
		return *this;
	}
	Rational operator-() const
	{
		Rational tmp(numerator_, denominator_);
		tmp.neg();
		return tmp;
	}
	Rational operator+() const
	{
		return *this;
	}
	friend bool operator==(const Rational& a, const Rational& b)
	{
		return ((a.numerator_==b.numerator_) && (a.denominator_==b.denominator_));
	}
	friend bool operator<(const Rational& a, const Rational& b)
	{
		return ((a.numerator_*b.denominator_) < (a.denominator_*b.numerator_));
	}*/

private:
    int numerator_;
    int denominator_;
};

/*Rational operator+(Rational r1, const Rational& r2)
{
	return r1 += r2;
}
Rational operator-(Rational r1, const Rational& r2)
{
	return r1 -= r2;
}
Rational operator*(Rational r1, const Rational& r2)
{
	return r1 *= r2;
}
Rational operator/(Rational r1, const Rational& r2)
{
	return r1 /= r2;
}
bool operator!=(const Rational& a, const Rational& b)
{
	return !(a==b);
}
bool operator>(const Rational& a, const Rational& b)
{
	return b < a;
}
bool operator<=(const Rational& a, const Rational& b)
{
	return !(b < a);
}
bool operator>=(const Rational& a, const Rational& b)
{
	return !(a < b);
}*/



int main()
{
    Rational r1(-1, 2);
    //std::cout << r1.to_double() << std::endl;	// 0.5
    std::cout << r1 << std::endl;	// 0.5
    Rational r2(1, 3);
    //std::cout << r2.to_double() << std::endl;	// 0.333
	std::cout << r2 << std::endl;	// 0.333
	std::cout << "------------------" << std::endl;

	// test methods
    //r1.add(r2);
	/*r1 += r2;
    std::cout << r1.to_double() << std::endl;	// 0.833
    
	//r1.sub(r2);
	r1 -= r2;
    std::cout << r1.to_double() << std::endl;	// 0.5
       
	//r3.mul(r1);
	r3 *= r2;
    std::cout << r3.to_double() << std::endl;	// 1.666

    //r3.div(r2);
	r3 /= r2;
    std::cout << r3.to_double() << std::endl;	//	5

	//r1.neg();
	r1 = -r1;
    std::cout << r1.to_double() << std::endl;	// -0.5
	*/


	// test operators
	/*Rational r3 = r1 + r2;
    std::cout << r3.to_double() << std::endl;	// 0.833

	Rational r4 = r1 - r2;
    std::cout << r4.to_double() << std::endl;	// 0.166

	Rational r5 = r1 * r2;
    std::cout << r5.to_double() << std::endl;	// 0.166

	Rational r6 = r1 / r2;
    std::cout << r6.to_double() << std::endl;	// 1.5
	
	std::cout << "------------------" << std::endl;

	std::cout << (r1 == r1) << std::endl;
	std::cout << (r1 != r1) << std::endl;
	std::cout << (r1 > -1) << std::endl;
	std::cout << (r1 < -1) << std::endl;
	std::cout << (r1 >= r1) << std::endl;
	std::cout << (r1 <= -1) << std::endl;*/

}
