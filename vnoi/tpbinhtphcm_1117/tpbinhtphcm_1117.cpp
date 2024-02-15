/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 9;

bool multiTestCases = true;

int n;
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    int sum = 0;
	for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i*i == n) {
                sum += i;
            } else {
                sum += i;
                sum += n/i;
            }
        }
    }
    if(sum >= n*2) cout<<1<<endl;
    else cout<<0<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
