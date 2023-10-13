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
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    const int cost = 6500;

    int tuan = n;
    int tuan_vo = tuan / cost;
    int tuan_remain = tuan - tuan_vo*cost;

    int thanh = 2*tuan;
    int thanh_vo = thanh / cost;
    int thanh_remain = thanh - thanh_vo * cost;

    int an = thanh - 10000;
    int an_vo = an / cost;
    int an_remain = an - an_vo*cost;

    int remain_vo = (tuan_remain + thanh_remain + an_remain) / cost;

    cout<<remain_vo + thanh_vo + an_vo + tuan_vo;
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