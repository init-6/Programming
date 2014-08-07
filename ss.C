#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	stringstream ss ;
	ss << "name b 4.5 8";
	string a;char b;double c;int d;
	ss >> a >> b >> c >> d;
	cout << a << " " << b << " " << c << " " << d << endl;
}
