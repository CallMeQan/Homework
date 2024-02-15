/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

bool multiTestCases = false;

int n, x, y;

void solve(){
    // Something goes here...
    cin>>n>>x>>y;
    int ans = 0;
    int tmp = x*y;
    for(int i = 1; i*tmp <= n; i++){
        ans++;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SHENYUN.INP", "r", stdin);
    freopen("SHENYUN.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
