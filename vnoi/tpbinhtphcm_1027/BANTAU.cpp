#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 409;

int dp[N][N], d[N], pre[N];
int n, k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre[0] = 0;
    cin>>n>>k;
    // N <= 400 => O(N^3) => 6*10^7
    int maxi = 0;
    for(int i = 1; i<=n; i++){
        cin>>d[i];
        pre[i] = pre[i-1] + d[i];
        // cout<<pre[i]<<" ";
        // 80 90 95 102 202 222 257
        maxi = max(maxi, d[i]);
        dp[i][0] = maxi*i - pre[i];
    }

    for(int i = 1; i<=k; i++){
        dp[0][i] = 0; // Ko ton tai 0
        dp[1][i] = 0; // Vi tri 1 luon ko bi tru diem
    }

    for(int i = 1;i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i][j] = dp[i][0];
            if(j+1>=i){
                dp[i][j] = 0;
                continue;
            }
            int maxX = 0;
            int maxSum = 0;
            for(int x = i; x >= 1; x--){
                maxX = max(maxX, d[x]);
                maxSum += d[x];
                dp[i][j] = min(dp[i][j], dp[x-1][j-1] + maxX*(i - x + 1) - maxSum);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
