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

int n,m, k;
int a[N][N];

void solve(){
    // THIS USED FOR A AND B
    int ans = 0;
    cin>>n>>m>>k;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++) {
            int num;
            cin>>num;
            if(num == k) ans++;
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