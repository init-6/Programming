#include <vector>
#include <queue>
#include <climits>
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
#include <cstring>
 
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> PI;
typedef vector <PI> VPI;

map <string, pair <string, string> > dict;
string global_context = "";

string createtype(string a, string b)
{
	if(a.sz == 0) return b;
	return a+"."+b;
}

void removetype(string a)
{
	if(global_context.sz == 0) return;

	reverse(all(a));
	string newctxt = "";
	bool dotfound = false;
	REP(i, a.sz) if(a[i] == '.')
	{
		newctxt = a.substr(i+1);
		dotfound = true;
		break;
	}
	if(!dotfound)
	{
		global_context = "";
		return;
	}
	reverse(all(newctxt));
	global_context = newctxt;
}

string removespaces(string a)
{
	string ret = "";
	REP(i, a.sz) if(a[i] != ' ')
	ret += a[i];

	return ret;
}



void parse(string line)
{
	if(line == "\n") return;
	if(line[line.sz-1] == ":") // Possible beginning of nested objects
	{
		global_context += line.substr(0,line.find(':'));
		cout << "Printing global_context from parse " << global_context << endl;
	}
	else if(line[line.sz-1] == '{' && line.sz == 1) return;
	else if(line[line.sz-1] == '}' && line.sz == 1)
	{
		removetype(line); // Ending object definition
	}
	else if(line[line.sz-1] == '{' && line.sz > 1)
	{
		global_context += line.substr(0,line.find(':'));
		cout << "Printing global_context from parse " << global_context << endl;
	}
	else if(line[line.sz-1] == '}' && line.sz > 1)
	{
		global_context = line.substr(0,line.find(':'));
		cout << "Printing global_context from parse " << global_context << endl;
		addtodict(line);
		removetype(line);
	}
	else addtodict(line);
}

int main()
{
	int N; cin >> N;
	int Q; cin >> Q;
	cin.ignore();
	REP(i, N)
	{
		string cur;
		getline(cin, cur);
		cur = removespaces(cur);
		cout << cur << endl;
		parse(cur);
	}
	return 0;
}
