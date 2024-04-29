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
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ld = long double;

bool loopInput = false;

int n;
int a[N], dp[N];

void solve(){
    // Something goes here...
    int sum = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i = 10; i<=n; i++){
        int f = 1e9+5;
        for(int j = i-9; j<=i; j++){
            f = min(f, a[j]);
        }
        dp[i] = max(dp[i-1], dp[i-10]+f);
    }
    cout<<sum-dp[n]<<endl;
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