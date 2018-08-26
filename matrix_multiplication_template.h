

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
