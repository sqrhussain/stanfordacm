#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define si(n)                       scanf("%d",&n)
#define sii(a,b)                    scanf("%d%d",&a,&b)
#define lp(i,n) 					for(int i=0;i<(int)n;i++)
#define lp1(i,n)					for(int i=1;i<=(int)n;i++)
const int N = 1e5 + 5;
const int LOGN = 20;
vi adj[N];
int dp[LOGN][N]; //sparse
int level[N];
int n;
int cs; //composition size
int sub[N];
bool cen[N];
int par[N];
int ans[N];
void dfs1(int u) {
	lp(i,adj[u].size())
	{
		int v = adj[u][i];
		if (v != dp[0][u]) {
			level[v] = level[u] + 1;
			dp[0][v] = u;
			dfs1(v);
		}
	}
}
void sparse() {
	dfs1(0);
	lp1(i,LOGN-1)
	{
		lp(j,n)
		{
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

}
int lca(int a, int b) {
	if (level[a] > level[b])
		swap(a, b);
	int dif = level[b] - level[a];
	lp(i,LOGN)
	{
		if (dif & (1 << i))
			b = dp[i][b];
	}
	if (a == b)
		return b;
	for (int i = LOGN - 1; i >= 0; i--) {
		if (dp[i][a] != dp[i][b])
			a = dp[i][a],b=dp[i][b];
	}
	return dp[0][a];
}
int dist(int a, int b) {
	return level[a] + level[b] - 2 * level[lca(a, b)];
}
/*----rot&decay--------*/
void dfssub(int u, int p) {
	sub[u] = 1;
	cs++;
	lp(i,adj[u].size())
	{
		int v = adj[u][i];
		if (!cen[v] && v != p)
			dfssub(v, u), sub[u] += sub[v];
	}
}
int dfscen(int u, int p) {
	lp(i,adj[u].size())
	{
		int v = adj[u][i];
		if (!cen[v] && v != p&&sub[v]>cs/2)
			return dfscen(v, u);
	}
	return u;
}
void decomp(int root, int p) {
	cs = 0;
	dfssub(root, p);
	int centroid = dfscen(root, p);
//	cout<<centroid<<endl;
	cen[centroid] = 1;
	par[centroid] = p;
	lp(i,adj[centroid].size())
	{
		if (!cen[adj[centroid][i]])
			decomp(adj[centroid][i], centroid);
	}

}
void update(int u) {
	int x = u;
	while (x != -1) {
		ans[x] = min(ans[x], dist(u, x));
		x = par[x];
	}

}
int query(int u) {
	int x = u;
	int mn = ans[u];
	while (x != -1) {
		mn = min(mn, ans[x] + dist(u, x));
		x = par[x];
	}
	return mn;
}
int main() {
	int m;
	sii(n, m);
	{
		int x,y;
		lp(i,n-1)
		{
			sii(x,y);
			x--;y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	sparse();
	decomp(0, -1);
	lp(i,n)ans[i]=1e9;
	update(0);
	while(m--){
//		int x,y;
//		cin>>x>>y;
//		cout<<dist(x,y)<<endl;
		int t,u;
		sii(t,u);
		u--;
		if(t==1)update(u);
		else printf("%d\n",query(u));
	}

}
