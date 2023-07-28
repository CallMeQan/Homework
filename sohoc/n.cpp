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

void solve(){
    cin>>n;
    int ans = 0;
    for (int i = 2; n != 1; i++) {
        if (n % i == 0) {
            int somu = 0;
            for (;n % i == 0; n /= i) {
                somu++;
            }
            if (somu > ans) ans = somu;
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