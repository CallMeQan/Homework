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

void dijk(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});
    while(!pq.empty()){
        int u = pq.top().se;
        int cost = pq.top().fi;
        pq.pop();
        for(pii x: a[u]){
            int v = x.se;
            int weight = x.fi;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
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
    dijk(1);
    cout<<dist[n]<<endl;
}
