/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 3008
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ld = long double;

bool loopInput = false;
int n;
int x[N],c[N];
pair <int,int> a[N] ;
int pref [N];
int dp[N][2];
int Sum(int l, int r) {
    return pref[r] - pref[l-1];
}
int SumDist(int l ,int r) {
    return Sum(l, r) - (r-l+1) * x[l] ;
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i].fi>>a[i].se;
    sort(a+1, a+1+n);
    for(int i = 1; i<=n; i++){
        x[i] = a[i].fi;
        pref[i] = pref[i-1]+x[i];
        c[i] = a[i].se;
    }
    dp[1][0] = 1e18;
    dp[1][1] = c[1];
    for(int i = 1; i<=n; i++){
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + c[i];
        dp[i][0] = 1e18;
        for(int j = 1; j<i; j++){
            dp[i][0] = min(dp[i][0], dp[j][1] + SumDist(j,i));
        }
    }
    cout<<min(dp[n][0], dp[n][1]);
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