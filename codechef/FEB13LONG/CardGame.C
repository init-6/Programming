#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MOD = 1000000007;

LL pow(LL a, int p) {
	if(p==0) return 1;
	if(p==1) return a;
	LL ret = pow(a,p>>1);
	(ret *= ret)%=MOD;
	if(p&1) (ret *= a)%=MOD;
	return ret;
}


int main()
{
	int N; cin >> N;
	int C[N];
	map <int, int> M;
	for(int i=0;i<N;i++)
	{
		cin >> C[i];
		M[C[i]]++;
	}

	map <int, int> :: iterator it;
	it = M.begin();

	for (int k=1;k<=1000;k++)
	{
		int color = k;

	}

	cout << pow(2,1000) << endl;

	return 0;
}
