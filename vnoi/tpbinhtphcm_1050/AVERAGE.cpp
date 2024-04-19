#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5+9;

int n, k;
int a[N], dp[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("AVERAGE.INP", "r", stdin);
    freopen("AVERAGE.OUT", "w", stdout);

    cin>>n>>k;
    for(int i = 1;i<=n; i++){
        cin>>a[i];
    }
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        int count_ = 1;
        int tmp = a[i];
        for(int j = i + 1; j<=n; j++){
            tmp += a[j];
            count_++;
            if(tmp / count_ > k) break;
        }
        dp[i] = max(count_, dp[i-1]);
    }
    cout<<dp[n]<<endl;
}
