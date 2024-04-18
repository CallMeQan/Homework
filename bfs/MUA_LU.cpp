#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 9;
const int INF = 1e9;

int n, m, x;
vector<int> a[N];
vector<int> infected;
bool visited[N];

void bfs(int where){
    queue<int> q;
    q.push(where);
    visited[where] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: a[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x;
    for(int i = 1; i<=m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        if(c >= x){
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        bfs(i);
        ans++;
    }
    cout<<ans;
}
