/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n,m;
array<pair<int,int>> a[N];
int dist[N];

priority_queue<pair<int,int>, array<pair<int,int>>, greater<pair<int,int>>> q;

void dijk(int start){
    for(int i = 1; i<=n; i++){
        dist[i] = 1e18;
    }
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