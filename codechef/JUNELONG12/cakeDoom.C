#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool noQ = true;
int nQ = 0;

bool validate(string s)
{
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] != '?' && s[i] == s[(i+1)%s.length()] && (i != (i+1)%s.length()))
		return false;
		if(s[i] == '?')
		noQ &= false, nQ++;
	}
	return true;
}

int main()
{
	int T;cin >> T;
	while(T--)
	{
		int K;cin >> K;
		noQ = true, nQ = 0;
		string s;cin >> s;
		bool isValid = validate(s);
		if(!isValid) {
			cout << "NO" << endl;
			continue;
		}

		if(isValid && noQ)
		{ 
			cout << s << endl;
			continue;
		}

		string ans = "";
		if(K == 1 && s.length() > 1)
		{cout << "NO" << endl;continue;}


		string srev = s;
		reverse(srev.begin(),srev.end());
		for(int i = 0;i < s.length();i++)
		{
			if(s[i] == '?')
			{
				for(int j = 0;j < K;j++)
				{
					if((s[(s.length()+i-1) % s.length()] - '0')!= j && j!= (s[(i+1)%s.length()] - '0'))
					{
						s[i] = (char) (j +'0');
						break;
					}
				}
			}
			if(srev[i] == '?')
			{
				for(int j = 0;j < K;j++)
				{
					if((srev[(s.length()+i-1) % s.length()] - '0')!= j && j!= (srev[(i+1)%s.length()] - '0'))
					{
						srev[i] = (char) (j +'0');
						break;
					}
				}
			}
		}

		reverse(srev.begin(), srev.end());
		bool f1 = false, f2=false;
		for(int i = 0;i<s.length();i++)
		{
			if(s[i] == '?')
			f1 = true;
			if(srev[i] == '?')
			f2 = true;
		}

		f1 == true ? ( (f2 == true) ? cout << "NO" << endl : cout << srev << endl) : cout << s << endl;
	}
	return 0;
}
