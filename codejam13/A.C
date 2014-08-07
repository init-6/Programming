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

string board[4];
bool hasT;

bool isWin(char c)
{
	// leading diagonal (len 4)
	if(board[0][0] == c && board[1][1] == c && board[2][2] == c && board[3][3] == c)
		return true;
	// other diagonal (len 4)
	if(board[0][3] == c && board[1][2] == c && board[2][1] == c && board[3][0] == c)
		return true;
	// diagonals with T;
	if((board[0][0] == c || board[0][0] == 'T') && board[1][1] == c && board[2][2] == c && board[3][3] == c)
		return true;
	if((board[1][1] == c || board[1][1] == 'T') && board[0][0] == c && board[2][2] == c && board[3][3] == c)
		return true;
	if((board[2][2] == c || board[2][2] == 'T') && board[1][1] == c && board[0][0] == c && board[3][3] == c)
		return true;
	if((board[3][3] == c || board[3][3] == 'T') && board[1][1] == c && board[2][2] == c && board[0][0] == c)
		return true;
	if((board[0][3] == c || board[0][3] == 'T') && board[1][2] == c && board[2][1] == c && board[3][0] == c)
		return true;
	if((board[1][2] == c || board[1][2] == 'T') && board[0][3] == c && board[2][1] == c && board[3][0] == c)
		return true;
	if((board[2][1] == c || board[2][1] == 'T') && board[0][3] == c && board[1][2] == c && board[3][0] == c)
		return true;
	if((board[3][0] == c || board[3][0] == 'T') && board[0][3] == c && board[2][1] == c && board[1][2] == c)
		return true;

	// for len 4 rows
	bool ans = true;
	REP(i,4)
	{
		ans = ans && (board[0][i] == c || board[0][i] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[1][i] == c || board[1][i] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[2][i] == c || board[2][i] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[3][i] == c || board[3][i] == 'T');
	}
		if(ans)
			return ans;
	// for columns
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[i][0] == c || board[i][0] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[i][1] == c || board[i][1] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[i][2] == c || board[i][2] == 'T');
	}
		if(ans)
			return ans;
	ans = true;
	REP(i,4)
	{
		ans = ans && (board[i][3] == c || board[i][3] == 'T');
	}
		if(ans)
			return ans;

	return false;
}


int main()
{
	int T;cin >> T;
	REP(c,T)
	{
		REP(i,4)
			cin >> board[i];

		bool draw = true;
		hasT=false;
		int cX=0, cO=0;
		REP(i,4)
		{
			REP(j,4)
			{
				if(board[i][j] == '.')
					draw = false;
				if(board[i][j] == 'T')
					hasT = true;
				if(board[i][j] == 'X')
					cX++;
				if(board[i][j] == 'O')
					cO++;
			}
		}

		if(draw)
		{
			// check for X win or O win.
			if(isWin('X'))
				cout << "Case #" << c+1 << ": " <<"X won" << endl;
			else if (isWin('O'))
				cout << "Case #" << c+1 << ": " <<"O won" << endl;
			else
				cout << "Case #" << c+1 << ": " <<"Draw" << endl;
		}
		else
		{
			if(!isWin('X') && !isWin('O'))
				cout << "Case #" << c+1 << ": " << "Game has not completed" << endl;
			else if(isWin('X'))
				cout << "Case #" << c+1 << ": " << "X won" << endl;
			else if(isWin('O'))
				cout << "Case #" << c+1 << ": " << "O won" << endl;
		}

		cin.get();
	}

	return 0;
}
