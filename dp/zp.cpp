/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000001
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

bool loopInput = true;

int n;
int dp[N];

void solve(){
    // Dùng pp sàn trước rồi output sau
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[0] = 0;
    for(int i = 1; i<=N; i++){
        dp[i] = dp[i-1] +1;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                int b = i/j;
                dp[i] = min(dp[i], dp[max(j, b)]+1);
            }
        }
    }
    if (loopInput){
        int t; cin >> t;
        while (t--) {
            cin>>n;
            cout<<dp[n]<<endl;
        }
    } else solve();
}