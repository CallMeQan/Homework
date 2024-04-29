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
const int N = 2e5 + 9;

bool multiTestCases = false;

int n;
int a[N], b[N], c[N];
map<double, int> cnt;
int ans = 0;

// https://www.vietjack.com/toan-lop-10/xac-dinh-vi-tri-tuong-doi-cua-hai-duong-thang.jsp
void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i]>>b[i]>>c[i];
        double res = (double)a[i] / b[i];
        cnt[res]++;
        ans += i - cnt[res];
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