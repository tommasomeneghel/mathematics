#pragma once

namespace tml
{

	class Complex
	{
	private:
		static int complex_count;

	public:
		static int get_complex_count(void);

		double real;
		double imaginary;
		Complex();
		Complex(double, double);
		~Complex();

		Complex& operator+ (Complex&);
		Complex& operator++ (void);
		Complex& operator- (Complex&);
		Complex& operator-- (void);

		Complex& operator* (Complex&);
		Complex& operator/ (Complex&);

	};
}

