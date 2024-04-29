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

bool loopInput = false;

bool isPerfectSquare(int n) {
    if(n == 0) return false;
    int root = sqrt(n);
    return root * root == n;
}

int n;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        dp[i] = 1;
        for(int j = max(1LL, i - 10); j<i; j++){
            if(isPerfectSquare(abs(a[j] - a[i]))){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
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