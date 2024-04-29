/*
    author: Qan
*/




// Nếu set multiTestCases thành false thì đây là solution cho bài C đề hsgioi tphcm 2022



#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e4 + 9;

bool multiTestCases = true;

int n, m, k, s, t;
int ans;
int dist[N], dist2[N];
vector <pii> adj[N];
vector <pii> adv[N];
priority_queue<pii, vector<pii>, greater<pii>> p;
priority_queue<pii, vector<pii>, greater<pii>> q;

void dijk(int start){
    for(int i = 1; i<=n; i++) dist[i] = 1e18;
    dist[start] = 0;
    q.push({dist[start], start});
    while(!q.empty()){
        int cost = q.top().fi;
        int x = q.top().se;
        q.pop();

        if(cost <= dist[x]){
            for(int i = 0; i< adj[x].size(); i++){
                int u = adj[x][i].fi;
                int w = adj[x][i].se;
                if(dist[u] > dist[x] + w){
                    dist[u] = dist[x] + w;
                    q.push({dist[u], u});
                }
            }
        }
    }
}

void dijk2(int start)
{
    for(int i=1;i<=n;i++) dist2[i]=1e18;
    dist2[start]=0;
    p.push({dist2[start], start});

    while(!p.empty())
    {
        int cost = p.top().fi;
        int x = p.top().se;
        p.pop();
        if(cost > dist2[x]) continue;

        for(int y = 0;y < adv[x].size(); y++)
        {
            int u = adv[x][y].fi;
            int w = adv[x][y].se;

            if(dist2[u] > dist2[x] + w)
            {
                dist2[u] = dist2[x] + w;
                p.push({dist2[u],u});
            }
        }

    }
}

void solve(){
    cin>>n>>m>>k>>s>>t;
    for(int i = 1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adv[v].push_back({u, w});
    }
    dijk(s);
    ans = dist[t];
    dijk2(t);
    for(int i = 1; i<=k; i++){
        int u, v, w;
        cin>>u>>v>>w;
        ans = min({ans, dist[u] + w + dist2[v], dist2[u] + w + dist[v]});
    }
    if(ans == 1e18) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        adv[i].clear();
    }
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
