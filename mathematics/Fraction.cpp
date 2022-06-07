#include "Fraction.h"

int tml::Fraction::fraction_count = 0;

tml::Fraction::Fraction() : numerator{ 0 }, denominator{ 0 } { tml::Fraction::fraction_count++; }
tml::Fraction::Fraction(int numerator, int denominator) : numerator{ numerator }, denominator{ denominator } { tml::Fraction::fraction_count++; this->simplify(); }
tml::Fraction::~Fraction() { tml::Fraction::fraction_count--; }

int tml::Fraction::get_fraction_count(void) { return tml::Fraction::fraction_count; }

void tml::Fraction::simplify(void)
{
	int gcd = tml::GCD(this->numerator, this->denominator);
	this->numerator /= gcd;
	this->denominator /= gcd;
}

int tml::GCD(int a, int b)
{
	if (a == 0)
		return b;
	return tml::GCD(b % a, a);
}

int tml::LCM(int a, int b)
{
	return a / (tml::GCD(a, b) * b);
}

tml::Fraction& tml::Fraction::operator+ (Fraction& right)
{
	int lcm = tml::LCM(this->denominator, right.denominator);
	int new_numerator = this->numerator * lcm / this->denominator +
		right.numerator * lcm / right.denominator;

	this->numerator = new_numerator;
	this->denominator = lcm;

	this->simplify();

	return *this;
}

tml::Fraction& tml::Fraction::operator++ (void)
{
	this->numerator += 1;

	this->simplify();

	return *this;
}

tml::Fraction& tml::Fraction::operator- (Fraction& right)
{
	int lcm = tml::LCM(this->denominator, right.denominator);
	int new_numerator = this->numerator * lcm / this->denominator -
		right.numerator * lcm / right.denominator;

	this->numerator = new_numerator;
	this->denominator = lcm;

	this->simplify();

	return *this;
}

tml::Fraction& tml::Fraction::operator-- (void)
{
	this->numerator -= 1;

	this->simplify();

	return *this;
}

tml::Fraction& tml::Fraction::operator* (Fraction& right)
{
	this->numerator *= right.numerator;
	this->denominator *= right.denominator;

	this->simplify();

	return *this;
}

tml::Fraction& tml::Fraction::operator/ (Fraction& right)
{
	tml::Fraction new_fraction{ right.denominator, right.numerator };

	return *this * new_fraction;
}
