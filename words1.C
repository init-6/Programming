#include <unistd.h>
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
#include <ctime>

#define V(x) vector<x >
#define sz size()
#define pb push_back
#define mp make_pair

typedef V(int) VI;typedef V(VI) VVI;
typedef pair<int,int> PII;
typedef long long LL;
typedef long double LD;

#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define INF (int)1e9
#define COUNT(f,x) ({int v=0;f v+=(x);v;})
void solve();

#define GI ({int t;scanf("%d",&t);t;})

#define DEBUG 0
#define PATH "e:/Prasanna/SPOJ/solves/"
#define PROGRAM "words1"
#define dprintf DEBUG && printf

int fid;
int main() {
	if(DEBUG) {
		assert(freopen(PATH PROGRAM ".in", "r", stdin)); 
		fid = dup( 1 );
		assert(freopen(PATH PROGRAM ".out", "w+", stdout)); 
	}
	for(int t=GI;t;t--) solve();
	if(DEBUG) { 
		fflush(stdout);
		fseek(stdout,0,0);
#define xwrite(a) write(fid,&a,sizeof(a)-1)
		xwrite("Standard out of the process :=\n");
		char c ;
		while( (c=fgetc(stdout))!=EOF ) write(fid,&c,1);
		fclose(stdout);
		REP(i,20) xwrite("-");xwrite("\n");
		while(1);
	}
}
/////////////////////////////////////////////////////////////////
#define MN 26
#define CLEAR(x) memset(&x,0,sizeof(x));
int graph[MN][MN];
int deg[MN],yeah[MN],seen[MN];
char buff[1024];
int dfs(int n) {
	if( seen[n] ) return 0;
	seen[n]=1;
	int r = 1;
	REP(i,MN) if( graph[n][i] ) r+=dfs(i);
	return r;
}
void solve() {
	int n = GI;
	CLEAR(graph);CLEAR(seen);CLEAR(deg);CLEAR(yeah);
	while( n-- ) {
		scanf("%s",buff);
		int f = buff[0]-'a', t = buff[strlen(buff)-1]-'a';
		graph[f][t]++;
		deg[f]++;deg[t]--;
		yeah[f]=yeah[t]=1;
	}
	bool ok=1; int odd=-1,nodd=0,nyeah=0;
	REP(i,MN) {
		if( yeah[i] ) { if(odd == -1) odd = i; nyeah++;}
		if( abs(deg[i]) > 1 ) ok=0;
		if( deg[i] ) {
			nodd++;
			if(deg[i]>0) odd = i;
		}
	}
	if( nodd > 2 || dfs(odd) != nyeah ) ok=0;
	if( ok ) cout<<"Ordering is possible.\n";
	else cout<<"The door cannot be opened.\n";
}

