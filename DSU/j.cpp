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

int n,m;
int a[N];

int acs(int u){
    if(a[u] == u) return u;
    return acs(a[u]);
}

void join(int u, int v)
{
    int x = acs(u);
    int y = acs(v);
    if(x != y) a[x] = y;
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        int c;
        cin>>c;
        a[i] = c;
    }

    for(int i = 1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        join(u,v);
        cout<<a[acs(u)]<<endl;
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