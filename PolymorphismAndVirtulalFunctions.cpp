#include <bits/stdc++.h>
using namespace std;

/*
A virtual function is member function which is derived in a base-class using keyword virtual which implies that this will be overriden in its base class.
In other words, virtual functions are resolved late, at runtime.
*/

/*
	Below is an example of runtime polymorphism. The main thing to note about is that the derived class fucntion is called using base class pointer. 
		The idea is that virtual function are called based on type of object instance pointed to or referenced to, not according to the type of pointer or reference.
		we store the address of each child class Rectangle and Square object in s and then we call the get_Area() function on it, ideally, it should have called the respective get_Area() functions of the child classes but instead it calls the get_Area() defined in the base class.
			This happens due static linkage which means the call to get_Area() is getting set only once by the compiler (at the compile time = early binding) which is in the base class.

		Hence we need virtula keyword, which wil allow compiler to see for theri definition at teh runctime based on the object instance the pointer is calling.
*/

// Base class
class Shape
{
protected:
	int length, width;
public:
	Shape(int l, int w)
	{
		this->length = l;
		this->width = w;
	}
	virtual int getArea()
	{
		cout << "This is call to parent class Area!\n";
	}
};

class Square: public Shape
{
public:
	Square(int l = 0, int w = 0):Shape(l, w)
	{
		this->length = l;
		this->width = w;
	}
	int getArea()
	{
		cout << "Area of Square: " << length * width << endl;
		return length * width;
	}
};

class Rectangle:public Shape
{
public:
	Rectangle(int l = 0, int w = 0):Shape(l, w)
	{
		length = l;
		width = w;
	}
	virtual int getArea()
	{
		cout << "Area of Rectangle: " << length * width << endl;
		return length * width;
	}
	
};

int main(int argc, char const *argv[])
{
	Shape* ptr;
	Square square(4,4);
	ptr = &square;
	ptr->getArea();
	Rectangle rect(7,9);
	ptr = &rect;
	ptr->getArea();
	return 0;
}

/*

Compiler adds additional code at two places to maintain and use vptr.
1) Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable of the class. 
2) Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is made, the compiler inserts code to first look for vptr using base class pointer or reference (In the above example, since pointed or referred object is of derived type, vptr of derived class is accessed). Once vptr is fetched, vtable of derived class can be accessed. Using vtable, address of derived derived class function show() is accessed and called. 

*/

// pure virtual Dtor:
/*
One of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor.

	Why we need pure virtual destructors??
		The reason is because destructors are not actually ‘overridden’, rather they are always called in the reverse order of the class derivation. 

	It is important to note that a class becomes abstract class when it contains a pure virtual destructor. For example, try to compile the following program.
*/