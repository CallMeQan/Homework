/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 590
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
int pre[N][N];
int pre2[N][N];
int a[N][N];

void solve(){
    int ans = INT64_MAX;
    // Something goes here...
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        pre[i][0] = 0;
        for(int j = 1; j <=n; j++){
            cin>>a[i][j];
            pre[i][j] = pre[i][j-1] + a[i][j];
        }
    }
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
            pre2[i][j] = pre2[i - 1][j] + pre[i][j];

    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            int pos[4]; // 4 coners
            pos[0] = pre2[i][j]; //top left
            pos[1] = pre2[i][n] - pos[0]; // top right
            pos[2] = pre2[n][j] - pos[0]; // bot left
            pos[3] = pre2[n][n] - pos[1] - pos[2] - pos[0]; //bot right
            sort(pos, pos + 4);
            ans = min(ans, pos[3] - pos[0]);
        }
    }
    cout<<ans;
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