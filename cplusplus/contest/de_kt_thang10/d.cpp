#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, k, a[N+5], dp[N+5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n + 1; i++){
        dp[i] = INT_MAX;
        for(int j = i; j >= i - k + 1 && j >= 0; j--){
            dp[i] = min(dp[i], dp[j] + a[i]);
        }
    }
    cout << dp[n+1];
    return 0;
}