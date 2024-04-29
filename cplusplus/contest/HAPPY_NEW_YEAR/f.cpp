/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool loopInput = false;

int n;
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i= 1 ;i<=n; i++) cin>>a[i];
    int ans = 0;
    for(int i=1; i<=n; i++){
        int tmp = a[i];
        if(tmp <= 2024) ans++;
        else continue;
        for(int j = i+1; j<=n; j++){
            tmp += a[j];
            if(tmp <= 2024) ans++;
            else break;
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