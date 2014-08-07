#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;cin >> T;
	string period = "415926530119026040722614947737296840070086399613316";
	while(T--)
	{
		int K;cin >> K;

		string ans="3.1";
		if(K==0) cout << 3 << endl;
		else if (K==1) cout << "3.1" << endl;
		else if (K <= 52)
		{
			ans+= period.substr(0,K-1);
			cout << ans << endl;
		}
		else
		{
			int n = (K-1)/51;
			while(n--) ans+= period;
			ans += period.substr(0, ((K-1)%51));
			cout << ans << endl;
		}
	}

	return 0;
}
