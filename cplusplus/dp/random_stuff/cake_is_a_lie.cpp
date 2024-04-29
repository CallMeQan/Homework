/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 10
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

int n, m, k;
int a[N+1][N+1], dp[N+1][N+1];

void solve(){
    // Something goes here...
    cin>>n>>m>>k;
    if(dp[n][m] == k){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a[1][1] = 0;
    // Move right (x, y+1) = x
    // Move down (x+1,y) = y
    for(int x = 2; x <= N; x++){
        a[x][1] = a[x-1][1] + 1;
        dp[x][1] = dp[x-1][1] + 1;
    }
    for(int y = 2; y <= N; y++){
        a[1][y] = a[1][y-1] + 1;
        dp[1][y] = dp[1][y-1] + 1;
    }
    // x go right, y go down
    for(int x = 2; x <= N; x++){
        for(int y = 2; y <= N; y++){
            a[x][y] = (x+y-2) + a[x-1][y] + a[x][y-1];
        }
    }
    for(int x = 1; x<=N;x++){
        for(int y = 1; y<=N; y++){
            cout<<a[x][y]<<" ";
        }
        cout<<endl;
    }
    dp[1][1] = a[1][1];
    for(int x = 2; x <= N; x++){
        for(int y = 2; y <= N; y++){
            dp[x][y] = dp[x-1][y] + dp[x][y-1];
        }
    }
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}