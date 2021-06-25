#include <bits/stdc++.h>
using namespace std;

// C++ has two types of polymorphism:
	// 1. Compile time
		/*
		Achived by function overloading or operator overloading
		Function overloading: functions with same name but different prototype
		different prototype means different number of arguments or/and change in type of arguments

		HOW FUNCTION OVERLOADING WORKS IN COMPILER??
			Exact match: name and parameters are same
			Not exact match: 
				-> char, unsigned char, and short are promoted to int
				-> float to double
			if no match found 
				-> C++ tries to find match by standard conversions
			Elset
				-> Throws an error

		OPERATOR OVERLOADING
			can we overload all operators?
				. (dot)
				::
				?:
				sizeof
				.* (pointer to member operator)
				this operators can't be overloaded

			IMP Points:
				1. for it work, at least one of the operands must be a user defined class object
				2. Assignment operator:
					default assignment operator copies all the members of right to left when used. this is same as copy ctor
				3. Conversion operator:
					to convert one type to another type
		*/

	
/*
class Fraction
{
	int num, den;
public:
	Fraction(int n, int d)
	{
		num = n;
		den = d;
	}

	// Conversion operator returns the float value of fraction class
	operator float() const 
	{
		return float(num)/float(den);
	}
};
*/


// operator overloading example:
/*
class Complex
{
	int real, img;
public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		img = i;
	}
	// this is called automatically whenever + is used between Complex objects
	Complex operator + (Complex const &obj)
	{
		Complex a;
		a.real = real + obj.real;
		a.img = img + obj.img;
		return a;
	}
	void print()
	{
		cout << "real: " << real << " img: " << img;
	}
};
*/

// 2. Run time
	// Achieved by function overriding
		/*
		Function overriding means redifinition of base class fucntion in its derived class with same signature i.e., same return type and same parameters
		*/

class Base
{
public:
	// this will be overrided inside derived class
	virtual void func()
	{
		cout << "inside base class\n";
	}
};

class derived:public Base
{
public:
	// here if we by mistake modifies the func's signature, then it will cause overloading instead of overriding
	void func() override
	{
		cout << "inside derived class\n";
	}
	// so inorder to aboid such a mistake c++ has an override keyword
};

int main(int argc, char const *argv[])
{
	// Complex c(4, 5);
	// Complex d(2, 3);
	// Complex e = c+d;
	// e.print();

	// Fraction f(4, 3);
	// cout << f;

	derived d;
	d.func();
	return 0;
}