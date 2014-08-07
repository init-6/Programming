#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int N;scanf("%d", &N);
	long long int adj[N][N];

	long long int dp[N+1][N+1];

	for(int i=0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			scanf("%lld", &adj[i][j]);
			dp[i][j] = adj[i][j];
		}
	}

	for(int k = 0;k<N;k++)
		for(int i = 0;i<N;i++)
			for(int j = 0;j<N;j++)
			{
				if(i!=j)
					dp[i][j] = min(dp[i][j], (long long) dp[i][k]+dp[k][j]);
			}
	long long int M;scanf("%lld", &M);
	for(int i=0;i<M;i++)
	{
		int S,G,D;scanf("%d%d%d", &S, &G, &D);
		printf("%lld %lld\n", dp[S][G]+dp[G][D], dp[S][G]+dp[G][D]-dp[S][D]);
	}



	return 0;
}

