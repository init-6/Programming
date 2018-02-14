#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS[5001][5001];

int getLCSLength(string A, string B, int N, int M)
{
	for (int i = 0; i <= N; i++)
	{
		LCS[i][0] = 0;
	}
	for (int i = 0; i <= M; i++)
	{
		LCS[0][i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (A[i-1] == B[j-1])
			{
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
	return LCS[N][M];
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int N, M;
		cin >> N >> M;

		string A, B, AComp, BComp;
		cin >> A;
		cin >> B;

		int i = 0;
		while (i < N)
		{
			AComp = AComp + A[i];
			while (i < N - 1 && A[i] == A[i + 1])
			{
				i++;
			}
			i++;
		}
		N = AComp.length();
		cout << AComp << "\n";

		i = 0;
		while (i < M)
		{
			BComp = BComp + B[i];
			while (i < M - 1 && B[i] == B[i + 1])
			{
				i++;
			}
			i++;
		}
		M = BComp.length();
		cout << BComp << "\n";

		int minFScore = N + M - getLCSLength(AComp, BComp, N, M);
		cout << minFScore << "\n";
	}

	return 0;
}
