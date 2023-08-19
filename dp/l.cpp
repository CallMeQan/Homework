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

int n,k;
int a[N], dp[N], b[N];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int ans = LLONG_MIN;
    int flag = 0;
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        flag += a[i];
        if(i>=k){
            b[i-k+1] = flag;
            flag -= a[i-k+1];
        }
        dp[i] = max(a[i], dp[i-1] + a[i]);
    }
    for(int i = 1; i <= n-k+1; i++){
        ans = max(ans, max(b[i]+dp[i-1], b[i]));
    }
    cout<<ans;
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