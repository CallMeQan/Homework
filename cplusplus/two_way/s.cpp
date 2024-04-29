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
const int N = 1e9 + 9;

bool multiTestCases = false;

int n, m, k;
int a[N][N];

void solve(){
    // Something goes here...
    cin>>n>>m>>k;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 1; i<=k; i++)
    {
        pii LeftTop, RightBot, RightTop, LeftBot;
        cin>>LeftTop.fi>>LeftTop.se>>RightBot.fi>>RightBot.se;
        // Input LeftTop and RightBot
        RightTop = {RightBot.fi, LeftTop.se};
        LeftBot = {LeftTop.fi, RightBot.se};
    }
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