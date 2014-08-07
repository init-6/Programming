#include <iostream>

using namespace std;

int main()
{
	cout << "Enter a string" << endl;
	string s;
	string rev;
	cin >> s;
	int len = s.length();
	for(int i = len-1;i >= 0; i--)
	{
		cout << s[i];
		rev += s[i];
	}
	cout << endl;
	// For palindrome, uncomment the below
	//if(s == rev) cout << "yes" << endl;
	//else cout << "no "<< endl;
	return 0;
}
