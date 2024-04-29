/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 200005
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
#define iii pair<pair<int,int>, int>
// [(x,y), c]

using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n, m, x, ans = 0;
array<int> village[N];
int a[N];

void DFS(int u)
{
    a[u] = 1;
    for(auto d: village[u]){
        if(a[d]) continue;
        DFS(d);
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m>>x;
    for(int i = 1; i<=m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        if(c < x) continue;
        village[u].push_back(v);
        village[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if (a[i]) continue;
        DFS(i); ans++;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
