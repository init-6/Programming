#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define len length()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef pair<int, int> PI;

int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		int N,M;cin >> N >> M;
		int lawn[N][M];
		REP(i,N)
		REP(j,M)
		cin >> lawn[i][j];

		int ones=0,twos=0;
		REP(i,N)
		REP(j,M)
		{
			if(lawn[i][j] == 2)
			twos++;
			if(lawn[i][j] == 1)
			ones++;
		}

		if(twos == N*M || ones == N*M)
		cout << "Case #" << c+1 << ": " << "YES" << endl;
		else if (N == 1 || M == 1)
		{
				cout << "Case #" << c+1 << ": " << "YES" << endl;
		}
		else
		{
			// If no 1s on the four boundaries and 1 inside the boundary - NO NO
			int bittoo=0;
			int flag = true;
			REP(j,M-2)
			{
				bool flag1=true, flag2=true;
				if(lawn[0][j+1] == 2)
				bittoo++;
				else if(lawn[0][j+1] == 1)
				{
					//check if all the row elements are 1 else set a flag
					REP(i,N)
					flag1 = flag1 && (lawn[i][j+1] == 1);
					REP(k,M)
					flag2 = flag2 && (lawn[0][k] == 1);
				}
				flag = flag && (flag1 || flag2);
			}
			REP(j,M-2)
			{
				bool flag1=true, flag2=true;
				if(lawn[N-1][j+1] == 2)
				bittoo++;
				else if(lawn[N-1][j+1] == 1)
				{
					//check if all the row elements are 1 else set a flag
					REP(i,N)
					flag1 = flag1 && (lawn[i][j+1] == 1);
					REP(k,M)
					flag2 = flag2 && (lawn[N-1][k] == 1);
				}
				flag = flag && (flag1 || flag2);
			}
			REP(i,N-2)
			{
				bool flag1=true, flag2=true;
				if(lawn[i+1][0] == 2)
				bittoo++;
				else if(lawn[i+1][0] == 1)
				{
					//check if all the row elements are 1 else set a flag
					REP(j,M)
					flag2 = flag2 && (lawn[i+1][j] == 1);
					REP(k,N)
					flag2 = flag2 && (lawn[k][0] == 1);
				}
				flag = flag && (flag1 || flag2);
			}
			REP(i,N-2)
			{
				bool flag1=true, flag2=true;
				if(lawn[i+1][M-1] == 2)
				bittoo++;
				else if(lawn[i+1][M-1] == 1)
				{
					//check if all the row elements are 1 else set a flag
					REP(j,M)
					flag1 = flag1 && (lawn[i+1][j] == 1);
					REP(k,N)
					flag2 = flag2 && (lawn[k][M-1] == 1);
				}
				flag = flag && (flag1 || flag2);
			}
			if(lawn[0][0] == 2 && lawn[0][M-1] == 2 && lawn[N-1][0] == 2 && lawn[N-1][N-1] == 2)
			{
				bittoo+=4;
			}
			if(lawn[0][0] == 1)
			{
				bool right=true;
				REP(j,M)
				right = right && (lawn[0][j] == 1);
				bool down=true;
				REP(i,N)
				down = down && (lawn[i][0] == 1);
				flag = flag && (right || down);
			}
			if(lawn[N-1][0] == 1)
			{
				bool right=true;
				REP(j,M)
				right = right && (lawn[N-1][j] == 1);
				bool up=true;
				REP(i,N)
				up = up && (lawn[i][0] == 1);
				flag = flag && (up || right);
			}
			if(lawn[N-1][M-1] == 1)
			{
				bool left=true;
				REP(j,M)
				left = left && (lawn[N-1][j] == 1);
				bool up=true;
				REP(i,N)
				up = up && (lawn[i][N-1] == 1);
				flag = flag && (up || left);
			}
			if(lawn[0][M-1] == 1)
			{
				bool left=true;
				REP(j,M)
				left = left && (lawn[0][j] == 1);
				bool down=true;
				REP(i,N)
				down = down && (lawn[i][M-1] == 1);
				flag = flag && (left || down);
			}

			if(bittoo == 2*M+2*(N-2))
			{
				// All 2s on the boundaries
				cout << "Case #" << c+1 << ": " << "NO" << endl;
			}
			else if(flag)
			{
				cout << "Case #" << c+1 << ": " << "YES" << endl;
			}
			else
				cout << "Case #" << c+1 << ": " << "NO" << endl;

		}
	}

	return 0;
}
