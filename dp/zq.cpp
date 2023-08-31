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

int n;
int a[N], dp[N], cnt[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    dp[1] = cnt[1];
    int ans = 0;
    for(int i = 1; i<=N;i++){
        for(int j = 2 * i; j<=N; j+= i){
            dp[j] = max(dp[j], dp[i]+cnt[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout<<n-ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(cnt,cnt+N, 0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}