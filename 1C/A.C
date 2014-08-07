#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

//vector <pair <int,int> > edges;
vector < vector <int> > adj;
bool visited[1005];
int edgeCount[1005];

bool dfs(int N)
{
	
	visited[N] = true;
	for(int i = 0;i<edgeCount[N];i++)
	{
		if(!visited[edges[N-1].second])
		{
			cout << "Dfs ing for node : " << edges[N-1].second << endl;
			visited[edges[N-1].second] = dfs(edges[N-1].second);
		}
		else return true;
	}
	
	return false;
	
}


int main()
{
	int T;cin >> T;
	
	for(int cases = 1;cases<=T;cases++)
	{
		edges.clear();
		int N; // no of nodes;
		cin >> N;
		
		memset(visited,false,sizeof(visited));
		memset(edgeCount,0,sizeof(edgeCount));
		for(int i = 1; i <= N; i++)
		{
			int nEdges;cin >> nEdges;
			edgeCount[i] = nEdges;
			while(nEdges--)
			{
				int node;
				cin >> node;
				//edges.push_back(make_pair(i,node));
			}
		}
		
		vector < pair <int,int> > :: iterator it;
		
		//sort(edges.begin(), edges.end());
		for(it=edges.begin();it!=edges.end();++it)
		{
			cout << it->first << "->" << it->second << endl;
		}
		
		
		// start dfs
		
		//for(int i = 0;i<N;i++)
		//{
			bool found = dfs(1);
			if(found)
				cout << "Yes" << endl;
			else
			cout << "No" << endl;
		//}
		
	}
	
	return 0;
}
