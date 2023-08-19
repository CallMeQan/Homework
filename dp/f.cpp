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
using ull = unsigned int;
using ld = long double;

bool loopInput = true;

int n, mod = 1e9 +7;
int a[N], dp[N];

void solve(){
    cin>>n;
    cout<<dp[n]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    // Something goes here...
    for(int i = 3; i <= 1e6; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}