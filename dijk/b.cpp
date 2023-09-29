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
const int N = 1e6 + 9;

bool multiTestCases = false;

int n,m;

vector<pii> a[N];
int dist[N], f[N], mini[N], maxi[N];

priority_queue<pii, vector<pii>, greater<pii>> q;

void dijk(int start){
    for(int i = 1; i<=n; i++){
        dist[i] = 1e18;
    }
    dist[start] = 0;
    f[start] = 1;
    q.push({dist[start], start});
    while(!q.empty()){
        int u = q.top().se;
        int cost = q.top().fi;
        q.pop();
        if(cost>dist[u]) continue;
        //cout<<u<<" "<< dist[u]<<endl;

        for(int i = 0; i<a[u].size(); i++){
            int v = a[u][i].fi;
            int w = a[u][i].se;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.push({dist[v], v});

                f[v] = f[u];
                maxi[v] = maxi[u] + 1;
                mini[v] = mini[u] +1;
            }else if(dist[v] == dist[u] + w){
                f[v] = (f[v] + f[u]) % MOD;
                maxi[v] = max(maxi[v], maxi[u] + 1);
                mini[v] = min(mini[v], mini[u]+1);
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
        //a[v].push_back({u,w});
        // Do bài này có hướng nên bỏ dòng trên
        // Khi vô hương như bài A nghĩa là vừa đi đến nó, vừa về lại vị trí cũ là vô hướng
    }
    dijk(1);
    if(dist[n]==1e18)
        cout<<"-1";
    else cout<<dist[n] << " " << f[n] << " " << mini[n] << " " << maxi[n] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}