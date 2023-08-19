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

bool check(int m, int k)
{
    int a = (m/2) + (m/3) - (m/6);
    return a>=k;
}

void solve(){
    int k;
    cin>>k;
    int l = 1, r = 1e14, ans = 0;
    while(l<=r){
        int m = (l+r)/2;
        if(check(m, k)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
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