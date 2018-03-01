#include <bits/stdc++.h>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
const int MOD = 1e9 + 7;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;
inline LL fpow(LL n, LL k, int p = MOD) {LL r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

struct Matrix
{
	static const int MAXN = 2;
	static const int MOD = 1e9 + 7;
	int x[MAXN][MAXN];

	Matrix() {
		memset(x, 0, sizeof(x));
	}

	static Matrix unit()
	{
		Matrix ret;
		REP(i, MAXN) ret[i][i] = 1;
		return ret;
	}

	int* operator [] (int r) {
		return x[r];
	}

	friend Matrix operator + (Matrix A, Matrix B) 
	{ 
		Matrix ret; 
		REP(i, MAXN) REP(j, MAXN)
		{
			ret[i][j] = A[i][j] + B[i][j];
			if(ret[i][j] >= MOD) ret[i][j] -= MOD;
		}
		return ret;
	}

	friend Matrix operator * (Matrix A, Matrix B)
	{
		Matrix res;
		REP(i, MAXN) REP(k, MAXN) REP(j, MAXN)
		{
			res[i][j] = (res[i][j] + (LL) A[i][k] * B[k][j]) % MOD;
		}
		return res;
	}

	friend Matrix operator ^ (Matrix A, LL r)
	{
		if(r == 0) return unit();
		Matrix ret, base;
		ret = unit(); base = A;

		while(r)
		{
			if(r&1) ret = ret * base;
			base = base * base;
			r >>= 1;
		}

		return ret;
	}
};


int main()
{
	
	return 0;
}
