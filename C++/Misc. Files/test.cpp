#include <iostream>
using namespace std;

class Hello{
	public:
	Hello();
	float getA();
	float getB();
	float getC();
	void inputA(int n);
	void inputB(int n);
	void inputC(int n);
	private:
	int a,b,c;
};
//handy little default constructor
Hello::Hello(){a=0;b=0;c=0;}

//getters... for some reason I defined these first
float Hello::getA(){return a;}
float Hello::getB(){return b;}
float Hello::getC(){return c;}

//setters... perhaps I should've defined these first
void Hello::inputA(int n){a=n;}
void Hello::inputB(int n){b=n;}
void Hello::inputC(int n){c=n;}

int main()
{
Hello foo;

foo.inputA(10);
foo.inputB(22);
foo.inputC(34);

cout<<foo.getA()<<endl;
cout<<foo.getB()<<endl;
cout<<foo.getC()<<endl;

return 0;
}
