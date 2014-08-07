#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MODU = 1000000007;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		LL N[3];
		cin >> N[0] >> N[1] >> N[2];

		sort(N,N+3);
		N[1] = N[1]--;
		N[2] = N[2]--;
		N[2] = N[2]--;

		N[0] = N[0]%MODU;
		N[1] = N[1]%MODU;
		N[2] = N[2]%MODU;

		LL ans = ((((N[0]*N[1])%MODU)*N[2])%MODU)%MODU;

		cout << ans << endl;
	}
	return 0;
}
