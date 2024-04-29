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

bool loopInput = true;

int n,x;
int a[N];
long double dp[N];
long double cal(long double money, int j, int i){
    return money * ((long double)a[i] / a[j]) - (long double) money * 2/100;
}

void solve(){
    // Something goes here...
    cin>>n>>x;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    dp[0] = x;
    for(int i = 1; i<=n; i++){
        dp[i] = dp[i-1];
        for(int j = 1; j <i; j++){
            dp[i] = max(dp[i], cal(dp[j-1], j, i));
        }
    }
    cout<<fixed<<setprecision(5)<<dp[n]<<endl;
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