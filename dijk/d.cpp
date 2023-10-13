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
const int N = 2e5 + 9;

bool multiTestCases = false;

int n, m, k;
int dist[N], dist2[N];
vector<pii> a[N];
vector<pii> b[N];

priority_queue<pii, vector<pii>, greater<pii>> q;
priority_queue<pii, vector<pii>, greater<pii>> p;

void dijk(int start){
    for(int i = 1; i<=n; i++) dist[i] = 1e18;
    dist[start] = 0;
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
 
        for(int y = 0;y < a[x].size(); y++)
        {
            int u = a[x][y].fi;
            int w = a[x][y].se;
 
            if(dist2[u] > dist2[x] + w)
            {
                dist2[u] = dist2[x] + w;
                p.push({dist2[u],u});
            }
        }
 
    }
}

void solve(){
    // Giống như bài C, dijka hai chiều nhưng có hướng
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        a[u].push_back({v, c});
    }
    dijk(1); //Binh
    dijk2(n);//An
    for(int i=1;i<=k;i++){
        int ans = 1e18;
        int a, b;
        cin>>a>>b;
        for(int j =1;j<=n;j++){
            if(dist[j] != 1e18 && dist2[j] != 1e18){
                ans = min(ans, a*dist[j] + b*dist2[j]);
            }
        }
        cout<<ans<<'\n';
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