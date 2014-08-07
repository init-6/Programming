#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 20000;

int T,N,Q;
int a[maxn],f[maxn];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

int main() {
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%d",&N);
		for (int i = 1;i <= N; i++) f[i] = i;
		for (int i = 1;i <= N; i++) scanf("%d",&a[i]);
		scanf("%d",&Q);
		for (int i = 1;i <= Q; i++) {
			int d,u,v;
			scanf("%d",&d);
			if (d == 0) {
				scanf("%d%d",&u,&v);
				u = find(u); v = find(v);
				if (u == v) printf("Invalid query!\n");
				else {
					if (a[u] < a[v]) f[u] = v;
					else if (a[u] > a[v]) f[v] = u;
				}
			}else {
				scanf("%d",&u);
				u = find(u);
				printf("%d\n",u);
			}
		}
	}
	return 0;
}
