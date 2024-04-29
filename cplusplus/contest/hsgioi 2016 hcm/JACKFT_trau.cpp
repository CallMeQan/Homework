/*
    author: Qan
*/
#include <bits/stdc++.h>
#define N 300005
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define endl "\n"
using namespace std;

int n, l, d;
pii a[N];

void solve(){
    cin>>n>>l>>d;
    for(int i = 1; i<=n; i++){
        cin>>a[i].fi;
    }
    for(int i = 1; i<=n; i++){
        cin>>a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1; i<=n; i++){
        for(int j = i; j>=i-l && j>=0; j--){

        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("JACKFT.INP", "r", stdin);
    freopen("JACKFT.OUT", "w", stdout);
    solve();
}
