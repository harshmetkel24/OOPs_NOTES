#include <bits/stdc++.h>
using namespace std;

class 
{
	int i;
public:
	// cannot have constructor or destructors
	void setData(int k)
	{
		this->i = k;
	}	
	void getData()
	{
		cout << "i: " << i << endl;
	}
}obj; // object of anonymous class
// these objects are global objects

int main(int argc, char const *argv[])
{
	obj.setData(5);
	obj.getData();
	return 0;
}