#include "Complex.h"

int tml::Complex::complex_count = 0;

tml::Complex::Complex() : real{0.0}, imaginary{0.0} { tml::Complex::complex_count++; }
tml::Complex::Complex(double real, double imaginary) : real{real}, imaginary{imaginary} { tml::Complex::complex_count++; }
tml::Complex::~Complex() { tml::Complex::complex_count--; }

int tml::Complex::get_complex_count(void) { return tml::Complex::complex_count; }

tml::Complex& tml::Complex::operator+ (Complex& right) 
{
	this->real += right.real;
	this->imaginary += right.imaginary;
	return *this;
}

tml::Complex& tml::Complex::operator++ () 
{
	this->real += 1.0;
	this->imaginary += 1.0;
	return *this;
}

tml::Complex& tml::Complex::operator- (Complex& right)
{
	this->real -= right.real;
	this->imaginary -= right.imaginary;
	return *this;
}

tml::Complex& tml::Complex::operator-- ()
{
	this->real -= 1.0;
	this->imaginary -= 1.0;
	return *this;
}

tml::Complex& tml::Complex::operator* (Complex& right) 
{
	this->real = (this->real * right.real) - (this->real * right.imaginary);
	this->imaginary = (this->real * right.imaginary) + (this->imaginary * right.real);
	return *this;
}

tml::Complex& tml::Complex::operator/ (Complex& right) 
{
	this->real = (this->real * 1 / right.real) - (this->real * 1 / right.imaginary);
	this->imaginary = (this->real * 1 / right.imaginary) + (this->imaginary * right.real);
	return *this;
}
