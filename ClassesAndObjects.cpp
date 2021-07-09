#include <bits/stdc++.h>
using namespace std;

// All the member functions that are defined inside class definition are called inline mumber functions

/* friend class and fucntion in C++ */
	// friend class can access private and protected members of the other class
	// friend functions can access private and protected members of that class
		// this freind function may a member variable of some other class or it can be a global function as wall
		// Remember this freindship is not mutual. It means if A freind of B. A then A can access members of B. but B cannot access of A.

// class Node
// {
// 	int key;
// 	Node* next;
// 	friend int ll::search(); // here only friend function of class ll can access the internal members of class Node.
// };

/*  CONSTRUCTORS */

	// default
class geeks
{
	int x;
public:
	geeks()
	{
		cout << "inside default.\n";
	}
	~geeks()
	{

	}
	void set(int x)
	{
		this->x = x;
	}
	void get()
	{
		cout << "x: " << x;
	}
	
};

	// copy constructors:
		// is a member function that initializes an object using another object of the same class.
		// prototype: ClassName (const ClassName &old_obj);
		// if we don't define our own copy ctor, then compiler does member-wise copy of objects member varibles
	// When user defined copy-constructor called?
		// generally compiler copy ctors are fine. But one needs to define own ctor only in case if object has pointers or any runtime allocation of resources like filehandling, connection, etc. is made.
	// Can copy ctor be private for any class?
		// Yeah copy ctor can be private. In that case the objects of that class are non copyable.
		// this becomes very helpful in case when we have some pointers or dynamic resource allocation. or another way would be to use our own copy ctor as in String class
	// Why argument to copy ctor must be by reference?
		// A copy constructor is called when an object is passed by value. A copy ctor itself is fucntion. So if we pass by value, then a call to copy ctor would be made to call to copy ctor which becomes non-terminating loop of calls. so compiler doesn't allow this.

class point
{
	int x,y;
public:
	point(int x1, int x2)
	{
		x = x1;
		y = x2;
	}
	point()
	{

	}
	~point(){}
	// Copy-constructor, here we use const bcoz we can't modify existing object p1 inside this code
	// point(const point &p1)
	// {
	// 	x = p1.x;
	// 	y = p1.y;
	// }
	void show()
	{
		cout << "x " << x << " y " << y; 
	}
};

// Another important example demosntrating need of Copy Ctors:
class String
{
	char* s;
	int size;
public:
	String(const char* s = NULL) // ctor
	{
		size = strlen(s);
		this->s = new char[size+1]; // to store null character
		strcpy(this->s, s);
	}
	~String(){delete []s;} // dtor
	// String(const String & old_str)
	// {
	// 	size = old_str.size;
	// 	this->s = new char[size+1];
	// 	strcpy(this->s, old_str.s);
	// }
	void show()
	{
		cout << "String is:\n" << this->s << endl;
	}
	void change(const char* s)
	{
		delete []s; // delete the original string already present
		size = strlen(s);
		this->s = new char[size+1];
		strcpy(this->s, s);
	}
};


int main(int argc, char const *argv[])
{
	String s1("hello This is Harsh");
	s1.show();
	String s2 = s1;
	s2.show();
	s2.change("hello this is harsh");
	s2.show();
	s1.show();
	return 0;
}