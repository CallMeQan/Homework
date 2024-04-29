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

int l,r;
int a[N];

void solve(){
    // Something goes here...
    cin>>l>>r;
    int tmp = 1;
    for(int i = l; i<=r; i++){
        tmp = (tmp * i) % 2024;
    }
    cout<<tmp;
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