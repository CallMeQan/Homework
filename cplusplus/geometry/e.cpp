/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n;
pii a[N];

void solve(){
    // Something goes here...
    cin>>n;
    int ans = 0;
    for(int i=1; i<=n; i++) cin>>a[i].fi>>a[i].se;
    for(int i = 1; i <= n; i++){
        for(int j = i; j<=n; j++){
            for(int k = j; k<=n; k++){
                ans += abs((a[j].fi - a[i].fi) * (a[k].se - a[i].se) - (a[k].fi - a[i].fi) * (a[j].se - a[i].se));
            }
        }
    }
    cout<<ans/2;
    if(ans % 2 == 0)cout<< ".0"<<endl;
	else cout<<".5"<<endl;
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