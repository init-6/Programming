#include <iostream>

using namespace std;

struct A
{
	int a;
	char b;
	void seta(int x)
	{
		a=x;
	}
	void setb(char t)
	{
		b=t;
	}
	void printa() {cout << "A : a " << a << endl;}
	void printb() {cout << "A : b " << b << endl;}
};

struct B : public A
{
	int c;
	char d;
	A a;
	void setc(int x)
	{
		c=x;
	}
	void setd(char t)
	{
		d=t;
	}
	void printc() {cout << "B : c " << c << endl;}
	void printd() {cout << "B : d " << d << endl;}
};

int main()
{
	A *a1 = new A();
	a1->seta(5);
	a1->setb('b');
	a1->printa();
	a1->printb();

	A *a2 = new B();
	a2->seta(6);
	a2->setb('c');
	a2->printa();
	a2->printb();

	B *b1, *b2;

	b1 = (B*) a1;
	b1->seta(6);
	b1->setb('c');
	b1->printa();
	b1->printb();
	b1->setc(6);
	b1->setd('c');
	b1->printc();
	b1->printd();

	b2 = (B*) a2;
	b2->seta(6);
	b2->setb('c');
	b2->printa();
	b2->printb();
	b2->seta(6);
	b2->setb('c');
	b2->printa();
	b2->printb();

	return 0;
}
