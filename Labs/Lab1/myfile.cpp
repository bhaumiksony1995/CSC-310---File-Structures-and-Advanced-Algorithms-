#include <iostream>
using namespace std;

class Base
{
	public :
		virtual void iam();
};

void Base::iam()
{
	cout << "base" << endl;
}

class Uno : public Base		//derived class Uno from class Base
{
	public:
		virtual void iam()
		{
			cout << "Class One" << endl;
		}

		virtual void iam2()
		{
			Base::iam();
		}
};

class Dos : public Base		//derived class Dos from class Base
{
	public :
		virtual void iam()
		{
			cout << "Class Two" << endl;
		}

		virtual void iam2()
		{
			Base::iam();
		}
};

int main()
{
	Uno one;		//declared object of class Uno
	Dos two;		//declared onject of class Dos

	Uno *One = &one;	//created pointer to the address of one
	Dos *Two = &two;	//created pointer to the address of two

	one.iam();		//calling the function iam() on one
	two.iam2();		//calling the function iam2() on one

	two.iam();		//calling the function iam() on two
	two.iam2();		//calling the function iam2() on two

	One -> iam();		//calling the function iam() through pointer *One
	One -> iam2();		//calling the function iam2() through pointer *One
	Two -> iam();		//calling the function iam() through pointer *Two
	Two -> iam2();		//calling the function iam2() through pointer *Two
return 0;
}
