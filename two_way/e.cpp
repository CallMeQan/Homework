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

int n;
int a[N][N];

void solve(){
    // Something goes here...
    int ans1 = 0;
    int ans2 = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            if(i==j) ans1 += a[i][j];
        }
    }
    for(int i = n; i>=1; i--){
        ans2 += a[i][n - i + 1];
    }
    cout<<ans1<<" "<<ans2;
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