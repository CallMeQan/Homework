#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 9;
const int INF = 1e10;

int n, m, k, s, t;

vector<pii> graph[N];
vector<pii> graph2[N];
// {weight, point}

int dist[N];
int dist2[N];
priority_queue<pii, vector<pii>, greater<pii>> q;

void reset(int n){
    for(int i = 1; i<=n; i++){
        graph[i].clear();
        graph2[i].clear();
    }
}

void dijk(int start){
    dist[start] = 0;
    q.push({dist[start], start});
    while(!q.empty()){
        int u = q.top().se;
        int cost = q.top().fi;
        if(cost > dist[u]) continue;
        q.pop();
        for(pii bruh: graph[u]){
            int v = bruh.se;
            int weight = bruh.fi;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                q.push({dist[v], v});
            }
        }
    }
}

void dijk2(int start){

    dist2[start] = 0;
    q.push({dist2[start], start});
    while(!q.empty()){
        int u = q.top().se;
        int cost = q.top().fi;
        if(cost > dist2[u]) continue;
        q.pop();
        for(pii bruh: graph2[u]){
            int v = bruh.se;
            int weight = bruh.fi;
            if(dist2[v] > dist2[u] + weight){
                dist2[v] = dist2[u] + weight;
                q.push({dist2[v], v});
            }
        }
    }
}

void solve(){
    cin>>n>>m>>k>>s>>t;
    for(int i = 1; i<=m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        dist[i] = INF;
        dist2[i] = INF;
        graph[u].pb({c, v});
        graph2[v].pb({c, u});
    }
    dijk(s);
    int ans = dist[t];
    dijk2(t);
    for(int i = 1; i<=k; i++){
        int u, v, c;
        cin>>u>>v>>c;
        ans = min({ans, dist[u] + c + dist2[v], dist2[u] + c + dist[v]});
    }
    if(ans == INF){
        cout<<-1<<endl;
    }else cout<<ans<<endl;
    reset(n);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
}
