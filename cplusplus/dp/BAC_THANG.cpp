/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ld = long double;

int mod = 14062008;
bool loopInput = false;

int n, k;
int a[N],dp[N];

void solve(){
    // Something goes here...
    fill(a+1, a+N+1, -1);
    cin>>n>>k;
    for(int i = 1; i<=k; i++){
        int ad = 0;
        cin>>ad;
        a[ad] = 0;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        if(a[i] == 0) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout<<dp[n];
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