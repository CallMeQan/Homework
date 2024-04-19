/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e6;
bool loopInput = false;

int n,m;
vector<pair<int,int>> a[N];
int dist[N];

priority_queue<pii, vector<pii>, greater<pii>> q;

void dijk(int start){
    dist[start] = 0;
    q.push({dist[start], start});
    while(!q.empty()){
        int u = q.top().fi;
        int cost = q.top().se;
        q.pop();
        if(cost>dist[u]) continue;;
        for(int i = 0; i<a[u].size(); i++){
            int next_pos = a[u][i].fi;
            int next_weight = a[u][i].se;
            if(dist[next_pos] > dist[u] + next_weight){
                dist[next_pos] = dist[u] + next_weight;
                q.push({dist[next_pos], next_pos});
            }
        }
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[i] = 1e18;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dijk(1);
    if(dist[n]==1e18)
        cout<<"-1";
    else cout<<dist[n];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
