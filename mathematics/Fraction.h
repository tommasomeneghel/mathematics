#pragma once

namespace tml
{

	class Fraction
	{
	private:
		static int fraction_count;

	public:
		static int get_fraction_count(void);

		int numerator;
		int denominator;
		Fraction();
		Fraction(int, int);
		~Fraction();

		void simplify(void);

		Fraction& operator+ (Fraction&);
		Fraction& operator++ (void);
		Fraction& operator- (Fraction&);
		Fraction& operator-- (void);

		Fraction& operator* (Fraction&);
		Fraction& operator/ (Fraction&);
	};

	int GCD(int, int);
	int LCM(int, int);
}


