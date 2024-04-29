#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, m;
vector<int> a[2005];
bool visited[2005];
void bfs(int k){
    queue<int> q;
    q.push(k);
    visited[k] = true;
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

void all_to_false(){
    for(int i = 1; i<=n; i++) visited[i] = false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROUTE.INP", "r", stdin);
    freopen("ROUTE.OUT", "w", stdout);

    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
        // city number x is connect to city number y. Both way.
        a[y].push_back(x);
    }
    all_to_false();
    bfs(1);
    int ans = 0;
    for(int i = 2; i<=n; i++){
        if(visited[i]) continue;
        ans++;
        bfs(i);
    }
    cout<<ans<<endl;
}
