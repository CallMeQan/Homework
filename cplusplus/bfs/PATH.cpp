/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD = 1e9+7;
const int N = 2e5 + 9;
const int INF = 1e18;

bool multiTestCases = false;

int n, m;
vector<int> a[N];
int dist1[N];
int dist2[N];

void reset(){
    for(int i = 1; i<=n; i++) dist1[i] = INF;
    for(int i = 1; i<=n; i++) dist2[i] = INF;
}

void bfs1(){
    queue<int> q;
    q.push(1);
    dist1[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x: a[u]){
            if(dist1[x] > dist1[u] + 1){
                dist1[x] = dist1[u] + 1;
                q.push(x);
            }
        }
    }
}

void bfs2(){
    queue<int> q;
    q.push(n);
    dist2[n] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x: a[u]){
            if(dist2[x] > dist2[u] + 1){
                dist2[x] = dist2[u] + 1;
                q.push(x);
            }
        }
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    reset();
    bfs1();
    bfs2();
    for(int i = 1; i<=n; i++){
        if(dist1[i] == INF || dist2[i] == INF){
            cout<<-1<<" ";
        }else{
            cout<<dist1[i] + dist2[i]<<" ";
        }
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