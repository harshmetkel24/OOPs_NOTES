#include <bits/stdc++.h>
using namespace std;

// Syntax:
// class sub_class:access_mode super_class
// {

// };

// Access modifiers:
	// 1. Public: public->public & protected->protected
	// 2. Protected: public->protected & protected->protected
	// 3. Private: public->private & protected->private
	// Note: private members of any base class are never inherited to any sub-class

// TYPES OF INHERITANCE:

// 1. Single Inheritance:
	// one sub class inherited by one base class
/*
class Vehicle
{
public:
	Vehicle()
	{
		cout << "Inside Vehicle ctor\n";
	}
};

class Car:public Vehicle
{
public:
	Car()
	{
		cout << "Inside Car ctor\n";
	}
};
*/

// 2. Multiple Inheritance:
	// inherit from more than one class
	// Syntax:
		// class derived:access_modifier class1, access_modifier class2, ...
		// {
		// 		body
		// }
	// Imp ponts:
		// Ctors of inherited class are called in the same order in which they are inherited. While dtors are called in the exact reverse order of ctors. Look at the below example of classes A, B and C. To understand this well.
		// Diamond problem:
			// Occurs when two base (super) classes of a class are them selves inherited by a commone base class.

// Ctors example
/*
class A
{
public:
	A()
	{
		cout << "A's ctor.\n";
	}
	~A()
	{
		cout << "A's dtor.\n";
	}
};

class B
{
public:
	B()
	{
		cout << "B's ctor.\n";
	}
	~B()
	{
		cout << "B's dtor.\n";
	}
};

class C:public B, public A
{
public:
	C()
	{
		cout << "C's ctor.\n";
	}
	~C()
	{
		cout << "C's dtor.\n";
	}
};
*/

// Diamond Problem:
// in this program the ctor and dtor of person is called two times. This implies that grand child TA has two copies of Person class. This may cause ambiguities.
// The solution to this problem is to use virtual keyword.
/*
class Person
{
public:
	Person(int x)
	{
		cout << "Person " << x << ".\n";
	}
	~Person()
	{
		cout << "Person's dtor.\n";
	}
};

class Faculty:public Person
{
public:
	Faculty(int x):Person(x)
	{
		cout << "Faculty " << x << endl;
	}
	~Faculty()
	{
		cout << "Faculty's dtor.\n";
	}
};

class Student:public Person
{
public:
	Student(int x):Person(x)
	{
		cout << "Student " << x << endl;
	}
	~Student()
	{
		cout << "Student's dtor.\n";
	}
};

class TA:public Faculty, public Student
{
public:
	TA(int x):Student(x), Faculty(x)
	{
		cout << "TA " << x << endl;
	}
	~TA()
	{
		cout << "TA's dtor.\n";
	}
};
*/

// Below is the solution to Diamond Problem, by making use of virtual keyword to base classes of Person i.e., Faculty & Student. This prevents creating multiple copies of Person class to TA class.

// But also note one imp thing in this program. The output shows default constructor of class Person. When we use virtual key word, then default ctor of grandparent is called by default even if the parent classes explicitly call parameterised ctor of grandparent.
/*
class Person
{
public:
	Person(int x)
	{
		cout << "Person " << x << ".\n";
	}
	Person()
	{
		cout << "Person called.\n";
	}
	~Person()
	{
		cout << "Person's dtor.\n";
	}
};

class Faculty: virtual public Person
{
public:
	Faculty(int x):Person(x)
	{
		cout << "Faculty " << x << endl;
	}
	~Faculty()
	{
		cout << "Faculty's dtor.\n";
	}
};

class Student: virtual public Person
{
public:
	Student(int x):Person(x)
	{
		cout << "Student " << x << endl;
	}
	~Student()
	{
		cout << "Student's dtor.\n";
	}
};

class TA:public Faculty, public Student
{
public:
	TA(int x):Student(x), Faculty(x)
	{
		cout << "TA " << x << endl;
	}
	~TA()
	{
		cout << "TA's dtor.\n";
	}
};
*/

// Demostration program to show how to call parameterised ctor of grandparent 
	// for this we need to explicity call that in ctor of grandchild

/*
class Person
{
public:
	Person(int x)
	{
		cout << "Person " << x << ".\n";
	}
	~Person()
	{
		cout << "Person's dtor.\n";
	}
};

class Faculty: virtual public Person
{
public:
	Faculty(int x):Person(x)
	{
		cout << "Faculty " << x << endl;
	}
	~Faculty()
	{
		cout << "Faculty's dtor.\n";
	}
};

class Student: virtual public Person
{
public:
	Student(int x):Person(x)
	{
		cout << "Student " << x << endl;
	}
	~Student()
	{
		cout << "Student's dtor.\n";
	}
};

class TA:public Faculty, public Student
{
public:
	TA(int x):Student(x), Faculty(x), Person(x) // explicit call of Person class
	{
		cout << "TA " << x << endl;
	}
	~TA()
	{
		cout << "TA's dtor.\n";
	}
};
*/

// Question 1:

// Ans:
	// here ambiguity arises as we have not used virtual keyword in B and C.
	// if we use it ans comes 20 as lastly we call ctor of C only
/*
class A
{
	int x;
public:
	void setx(int x)
	{
		this->x=x;
	}
	void print()
	{
		cout << "x is " << x;
	}
};

class B:public A
{
public:
	B()
	{
		setx(10);
	}
};

class C:public A
{
public:
	C()
	{
		setx(20);
	}
};

class D:public B, public C
{	
};
*/

// 3. Multi level inheritance
// derived class is created from another derived class
/*
class Vehicle
{
public:
	Vehicle()
	{
		cout << "inside Vehicle\n";
	}
};

class Fourwheel:public Vehicle
{
public:
	Fourwheel()
	{
		cout << "inside Fourwheel\n";
	}
};

class Car:public Fourwheel
{
public:
	Car()
	{
		cout << "inside car\n";
	}
};
*/


// 4. Hierarchial Inheritance:
// More than one derived classes are created from one single class

/*
class Vehicle
{
public:
	Vehicle()
	{
		cout << "inside Vehicle\n";
	}
};

class Car:public Vehicle
{
public:
	Car()
	{
		cout << "inside Car\n";
	}	
};

class Bus:public Vehicle
{
public:
	Bus()
	{
		cout << "inside Bus\n";
	}
};
*/

// 5. Hybrid inheritance:
//  this is done by combining more than one type of above mentioned inheritances

/*
// emample
// base class
class Vehicle
{
public:
	Vehicle()
	{
		cout << "inside Vehicle\n";
	}
};

// base class
class Fare
{
public:
	Fare()
	{
		cout << "inside Fare\n";
	}
};

// 1st subclass
class Car:public Vehicle
{
public:
	Car()
	{
		cout << "inside Car\n";
	}
};

// 2. sub class
class Bus:public Vehicle, public Fare
{
public:
	Bus()
	{
		cout << "inside Bus\n";
	}
	
};
*/

// 6. Multipath inheritance
// Same as Diamond Problem
	// here as D has two copies of A so one needs to specify path from which it needs to access the a

class A
{
public:
	int a;
};

class B:public A
{
public:
	int b;
};

class C:public A
{
public:
	int c;
};

class D:public B, public C
{
public:
	int d;
};

int main(int argc, char const *argv[])
{
	D obj;
	obj.C::a = 10;
	obj.B::a = 100;
	obj.b = 20;
	obj.c = 30;
	obj.d = 40;

	cout << "A from B: " << obj.B::a << endl;
	cout << "A form C: " << obj.C::a << endl;
	return 0;
}