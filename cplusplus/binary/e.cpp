/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
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
int a[N], b[N], c[N];

void solve(){
    int ans = 0;
    b[0] = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }
    for(int i = 1; i<=n; i++){
        cout<<(i*a[i] - b[i]) + (n-i) * (-a[i])+ b[n] - b[i]<<" ";
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