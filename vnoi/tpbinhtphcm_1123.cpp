#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N], dp[N];

void solve(){
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i];
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        int tmp = a[i];
        int coud = 1;
        bool flag = false;
        for(int j = i+1; j<=n; j++){
            if(tmp % k == 0){
                flag = true;
                break;
            }
            tmp += a[j];
            coud++;
        }
        if(!flag){
            dp[i] = dp[i-1];
        }else{
            dp[i] = dp[i-1]+coud;
        }
    }
    cout<<dp[n];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
