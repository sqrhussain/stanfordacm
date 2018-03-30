
int dfslow[N];
int dfsnum[N];
int dfscnt = 1;
vector<int> adj[N];
void dfs(int u, int p) {
  dfslow[u] = dfsnum[u] = dfscnt++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (!dfsnum[v]) {
      dfs(v, u);
      if(dfslow[v]>dfsnum[u]){
        //it's a bridge
      }
      dfslow[u]=min(dfslow[u],dfslow[v]);
    }else if(v!=p){
      //back edge
      dfslow[u]=min(dfslow[u],dfsnum[v]);
    }
  }
}
