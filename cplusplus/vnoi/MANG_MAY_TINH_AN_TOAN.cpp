/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
using namespace std;
const int N = 2005;
bool loopInput = false;

int n,m;
vector<int> a[N];

bool visited[N];

int dfs(int st){

}

void solve(){
    cin>>n>>m;
    int u, v;
    for(int i = 1; i<=n; i++){
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }

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
