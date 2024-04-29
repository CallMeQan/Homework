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
const int MOD = 1e9+7;
const int N = 505;
const int INF = 1e18;

bool multiTestCases = false;

int n,m;
int a[N][N];
int mapp[N][N];
int dist[N][N];
int moveX[4] = {1, 0,-1, 0};
int moveY[4] = {0, 1, 0,-1};
vector<pii> holes;

void reset(){
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            dist[i][j] = INF;
        }
    }
}

void bfs(int stx, int sty){
    queue<pii> q;
    q.push({stx, sty});
}

void solve(){
    // Something goes here...
    cin>>m>>n;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin>>mapp[i][j];
            if(mapp[i][j] == 1){
                holes.push_back({i, j});
            }
        }
    }
    int ans = INF;
    for(pii w: holes){
        reset();
        bfs(w.fi, w.se);
        int tmp = INF;
        for(pii check: holes){
            if(w.fi == check.fi && w.se == check.se) continue;
            if(dist[check.fi][check.se] == INF) break;
            tmp = min(tmp, dist[check.fi][check.se]);
        }
        ans = min(tmp, ans);
    }
    cout<<ans;
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