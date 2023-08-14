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

bool loopInput = false;

int n, k;
int a[N], dp[N];

void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        dp[i] = 1e8;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j >= max((long long)1, i-k); j--){
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
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