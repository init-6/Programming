#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include<algorithm>
using namespace std;
int n,m;
int map[102][102];
int match[102][102];
int du[102];
int path[102];
bool ifv[102];
int be;
bool dfs(int i,int k)
{
	if ((k&1) && !du[i] )
	{
		int t=k-1;
		while (t>=0)
		{
			if (match[i][path[t]]==0) {++du[i];++du[path[t]];}
			else {--du[i];--du[path[t]];}
			match[i][path[t]]=!match[i][path[t]];
			match[path[t]][i]=!match[path[t]][i];
			i=path[t];
			--t;
		}
		return true;
	}
	for (int j=1;j<=n;++j)
	{
		if (map[i][j]==-1) continue;
		if (match[i][j]!=(k&1) ) continue;
		if (ifv[j]) continue;
		path[k]=i;
		ifv[j]=true;
		if (dfs(j,k+1)) return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(map,-1,sizeof map);
		memset(match,0,sizeof match);
		memset(du,0,sizeof du);
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
		}
		if (n&1) puts("NO");
		else
		{
			int ans=0;
			for (int i=1;i<=n;++i)
			{
				memset(ifv,0,sizeof ifv);
				ifv[i]=true;
				if (!du[i] && dfs(i,0)) ++ans;
			}
			if (ans==n/2) puts("YES"); else puts("NO");
		}
	}
}
