#include <iostream>
using namespace std;

//display ordered pairs of any given type, which will be //determined by the user

template <class T>
class Pairs
{
	public:
	
	Pairs(){a=0;b=0;}
	Pairs(T n, T m){a=n;b=m;}
	void setA(T n){a=n;}
	void setB(T n){b=n;}
	
	void displayPair(){cout<<"("<<a<<","<<b<<")"<<endl;}
	
	T getA(){return a;}
	T getB(){return b;}
	
	private:
	
	T a,b;
};


int main()
{
	
	Pairs <int>foo(1,2);
	Pairs <char>loo('a','b');
	Pairs <float>moo(3.14,2.71);
	
	foo.displayPair();
	loo.displayPair();
	moo.displayPair();
	
	
	
	
	return 0;
	
}