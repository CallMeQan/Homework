#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 9;

int n, m;
vector<pii> a[N];
// {weight, point}
int dist[N];
int dp[N];

priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijk(int start){
    dist[start] = 0;
    pq.push({dist[start], start});
    dp[start] = 0;
    while(!pq.empty()){
        int u = pq.top().se;
        int cost = pq.top().fi;
        pq.pop();
        if(cost > dist[u]) continue;
        for(pii x: a[u]){
            int v = x.se;
            int weight = x.fi;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                dp[v] = dp[u] + 1;
                cout<<"Visited from "<<u<<" to "<<v<<" with "<<dp[v]<<endl;
            }else if(dist[v] == dist[u] + weight){
                dp[v] = 0;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        a[u].push_back({c, v});
        a[v].push_back({c, u});
        dist[i] = 1e18;
    }
    int ans = 0;
    dijk(1);
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    cout<<dist[n]<<endl;
}
