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

bool multiTestCases = false;

int n, m;
int dist[N], dist2[N], f1[N], f2[N];
vector<pii> a[N];
vector<pii> b[N];
vector<int> ans;

priority_queue<pii, vector<pii>, greater<pii>> q;

void dijk(int start){
    for(int i = 1; i<=n; i++) dist[i] = 1e18;
    dist[start] = 0;
    f1[start] = 1;
    q.push({dist[start], start});
    while(!q.empty()){
        int cost = q.top().fi;
        int x = q.top().se;
        q.pop();
        
        if(cost <= dist[x]){
            for(int i = 0; i< a[x].size(); i++){
                int u = a[x][i].fi;
                int w = a[x][i].se;
                if(dist[u] > dist[x] + w){
                    dist[u] = dist[x] + w;
                    f1[u] = f1[x];
                    q.push({dist[u], u});
                }
                if(dist[u] == dist[x] + w){
                    f1[u] = (f1[u] % MOD + f1[x] % MOD) % MOD;
                }
            }
        }
    }
}

void dijk2(int start)
{
    for(int i=1;i<=n;i++) dist2[i]=1e18;
    dist2[start]=0;
    f2[start] = 1;
    q.push({dist2[start], start});

    while(!q.empty())
    {
        int cost = q.top().fi;
        int x = q.top().se;
        q.pop();
        if(cost > dist2[x]) continue;
 
        for(pii y : a[x])
        {
            int u = y.fi;
            int w = y.se;
 
            if(dist2[u] > dist2[x] + w)
            {
                dist2[u] = dist2[x] + w;
                f2[u] = f2[x];
                q.push({dist2[u],u});
            }
            if(dist2[u] == dist2[x] + w){
                f2[u] = (f2[u] % MOD + f2[x] % MOD) % MOD;
            }
        }
 
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(pii(v,w));
        a[v].push_back(pii(u,w));
    }
    dijk(1);
    dijk2(n);
    for(int i=2; i<n; i++)
        if(!(dist[i] + dist2[i] == dist[n] && (f1[i] * f2[i])%MOD == f1[n]))
        {
            ans.push_back(i);
        }
    cout<<ans.size()<<'\n';
    for(int i : ans) cout<<i<<'\n';
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