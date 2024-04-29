/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 306
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

int n,k;
int a[N], dp[N][N], b[N];

void solve(){
    // Bài này về một thg simp đi tặng gái bông hoa
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i]>>b[i];
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++) dp[i][j] = -1e9;
    }
    for(int i = 1; i<=n; i++){
        dp[i][1] = b[i];
        for(int j = 2; j<=k; j++){
            dp[i][j] = -1e9;
            for(int x = 1; x<i; x++){
                if(a[i]!= a[x]) dp[i][j] = max(dp[i][j], dp[x][j-1]+b[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++) ans = max(ans, dp[i][k]);
    if(ans == 0) cout<<-1<<endl;
    else cout<<ans<<endl;
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