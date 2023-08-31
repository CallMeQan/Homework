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
int a[N];
int dp[N][3];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1 ;i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int j = 1;
    for(int i = 1; i<=n; i++){
        while(a[j]<a[i]-k)j++;
        dp[i][1] = max(dp[i-1][1], i-j+1);
        dp[i][2] = max(dp[i-1][2], dp[j-1][1] + (i-j+1));
    }
    cout<<dp[n][2];
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