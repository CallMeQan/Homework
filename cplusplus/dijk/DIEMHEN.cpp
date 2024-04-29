#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 9;
const int INF = 1e10;

int n, m, k;
vector<pii> path[N];
// {weight, point}

int dist[N];
int dist2[N];

priority_queue<pii, vector<pii>, greater<pii>> q;
priority_queue<pii, vector<pii>, greater<pii>> q2;

void dijk(int start){
    for(int i= 1; i<=n; i++) dist[i] = INF;
    dist[start] = 0;
    q.push({dist[start], start});
    while(!q.empty()){
        int u = q.top().se;
        int cost = q.top().fi;
        q.pop();
        if(cost > dist[u]) continue;
        for(pii val: path[u]){
            int next = val.se;
            int weight = val.fi;
            if(dist[next] > dist[u] + weight){
                dist[next] = dist[u] + weight;
                q.push({dist[next], next});
            }
        }
    }
}

void dijk2(int start){
    for(int i = 1; i<=n; i++) dist2[i] = INF;
    dist2[start] = 0;
    q2.push({dist2[start], start});
    while(!q2.empty()){
        int u = q2.top().se;
        int cost = q2.top().fi;
        q2.pop();
        if(cost > dist2[u]) continue;
        for(pii val: path[u]){
            int next = val.se;
            int weight = val.fi;
            if(dist2[next] > dist2[u] + weight){
                dist2[next] = dist2[u] + weight;
                q2.push({dist2[next], next});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 1; i<=m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        dist[i] = INF;
        dist2[i] = INF;
        path[u].pb({c, v});
    }
    dijk(1);
    dijk2(n);
    for(int i=1;i<=k;i++){
        int ans = INF;
        int a, b;
        cin>>a>>b;
        for(int j =1;j<=n;j++){
            if(dist[j] != INF && dist2[j] != INF){
                ans = min(ans, a*dist[j] + b*dist2[j]);
            }
        }
        cout<<ans<<'\n';
    }
}
