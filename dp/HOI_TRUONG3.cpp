/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100006
#define fi first
#define se second
#define pb push_back
#define int long long
#define vec vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ld = long double;

bool loopInput = false;

int n;
vec<pair<int,int>> a[N];
int dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        int p, k, c;
        cin>>p>>k>>c;
        a[k].push_back(make_pair(p,c));
    }
    int ans = 0;
    dp[0] = 0;
    for(int k = 1; k<=100000; k++){
        dp[k] = dp[k-1];
        for(int j = 0; j < a[k].size(); j++){
            int p = a[k][j].fi;
            dp[k] = max(dp[k], dp[p] + a[k][j].se);
        }
    }
    cout<<dp[100000];
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