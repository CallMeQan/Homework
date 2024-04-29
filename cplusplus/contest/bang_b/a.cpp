/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

bool multiTestCases = false;

int n;

void solve(){
    // Something goes here...
    cin>>n;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int tmp = 0;
        for (long long i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                if (i*i == n) {
                    tmp++;
                } else {
                    tmp+=2;
                }
            }
        }
        if(tmp % 2 == 0) ans++;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
