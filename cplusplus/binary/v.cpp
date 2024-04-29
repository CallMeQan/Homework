/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 505
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

// n = row
// m = col
// q = query
int n, m, q;
int a[N][N] = {0};

void solve(){
    // Something goes here...
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    while(q--){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<a[x2][y2] - a[x2][y1-1] - a[x1-1][y2] + a[x1-1][y1-1]<<endl;
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