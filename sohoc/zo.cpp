/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 2000006
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

void solve(){
    array<int> uoc(2e6 + 2, 0);
    int ans = 0;
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j+=i){
            uoc[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(uoc[i] == k) ans++;
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