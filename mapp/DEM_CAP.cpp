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

int n,k;
map<int, int> a;

void solve(){
    // Something goes here...
    int ans = 0;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int s;
        cin>>s;
        ans += a[k-s];
        a[s]++;
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