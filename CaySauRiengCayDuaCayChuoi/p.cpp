/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5 + 9;

bool multiTestCases = true;

vector<pii>g[N + 10];
int h[N + 10], cost[N + 10];
int par[N + 10][25],n,q;

void dfs(int u, int v){
    par[u][0] = v;
	for (auto x: g[u]) {
		int p = x.fi; 
        int c = x.se;
		if (p == v) continue;
		h[p] = h[u] + 1;
		cost[p] = cost[u] + c;
		dfs(p,u);
	}
}

void build(){
	for(int i = 1; (1<<i) <= n;i++)
        for(int j=1;j<=n;j++)
           p[j][i] = p[p[j][i-1]][i-1];
}

int lca(int u,int v) {
	if(h[u] < h[v])
        swap(u, v);
 
    int z = log2(h[u]);
    for(int i = z; i>=0 ;i--)
        if(h[u] - (1<<i) >= h[v])
           u = p[u][i];
 
    if(u==v) return v;
 
    for(int i=z;i >= 0;i--)
        if(p[u][i]  != p[v][i])
    {
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];

}

void solve(){
    // Something goes here...
    int u,v;
    cin >> u >> v;
    int p = lca(u,v);
    cout << cost[u] + cost[v] - 2 * cost[p] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u,v, w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
    build();
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}