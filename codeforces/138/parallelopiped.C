#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int lb, bh, hl;
	cin >> lb >> bh >> hl;
	int l=0,b=0,h=0;
	 b = (int) sqrt((lb*bh)/hl);
	 l = (int) sqrt((lb*hl)/bh);
	 h = (int) sqrt((bh*hl)/lb);
	
	cout << 4*(b+l+h) << endl;
	return 0;
}
