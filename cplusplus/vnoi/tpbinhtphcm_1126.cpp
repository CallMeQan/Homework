#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e4+5;

int n;
string str[N];
int dp[N][N];

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>str[i];
        dp[i][0] = 0;
    }
    for(int i = 1; i<=n; i++){
        int cur = 1;
        int count_;
        for(char c: str[i]){
            if(c == 'W' || c == 'A' || c == 'R'){
                dp[i][cur] = 0;
                count_ = 0;
                continue;
            }else dp[i][cur] = max(count_, dp[i][cur-1]);
            cur++;
            count_++;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
