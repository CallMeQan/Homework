/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000016
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

int n, q;
int a[N], b[N], c[N];

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    cin>>q;
    for(int i = 1; i <= q; i++){
        int l, r, x;
        cin>>l>>r>>x;
        b[l] += x;
        b[r+1] -= r-l+x;
        c[l+1]++;
        c[r+1]--;
    }
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
	for (int i = 1; i <= n; i++) b[i] += b[i - 1] + c[i];
    for(int i = 1; i <= n; i++) cout<<a[i] + b[i]<<" ";
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