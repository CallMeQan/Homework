#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 409;

int dp[N][N], a[N];
int n, k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BANTAU.INP", "r", stdin);
    freopen("BANTAU.OUT", "w", stdout);
    cin>>n>>k;
    int maxi = 0, maxsum = 0;;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        maxi = max(a[i], maxi);
        maxsum += a[i];
        dp[i][0] = maxi*i - maxsum;
    }
    for(int i = 1; i<=k; i++){
        dp[1][i] = 0;
        dp[0][i] = 0;
    }
    for(int i = 1;i<=n; i++){
        for(int j = 1; j<=k; j++){
            if(j+1>=i){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][0];
            int maxd = 0;
            maxsum = 0;
            for(int t = i; t>=1; t--){
                maxd = max(maxd, a[t]);
                maxsum += a[t];
                dp[i][j] = min(dp[i][j], dp[t-1][j-1] + maxd* (i - t + 1) - maxsum);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
