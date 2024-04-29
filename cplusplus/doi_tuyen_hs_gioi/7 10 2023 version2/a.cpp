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

int a,b,c;
int a[N];

void solve(){
    // Something goes here...
    int a, b, c;
    cin>>a>>b>>c;
    for(int i=1; i<=3; i++){
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
    }
    cout<<b;
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