/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1006
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

int n,m,u,v;
int a[N][N];

void solve(){
    // Something goes here...
    int ans1 = 0; // cheo1
    int ans2 = 0; // cheo2
    int ans3 = 0; // vertical
    int ans4 = 0; // hor
    cin>>n>>m>>u>>v;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= m; j++){
            int num;
            cin>>num;
            a[i][j] = num;
            if(i==j) ans1 += num;
            if(j==v) ans3 += num;
            if(i==u) ans4 += num;
        }
    }
    for(int i = v; i>=1; i--){
        ans2 += a[i][n - i + 1];
    }
    for(int i = v; i<=n; i++){
        if(u-i<=0)break;
        ans2 += a[i][u - i];
    }

    for(int i = v; i>=1; i--){
        ans1 += a[i][n - i + 1];
    }
    for(int i = v; i<=n; i++){
        if(u-i<=0)break;
        ans1 += a[i][u - i];
    }
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