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
    for(int i = 1; i<=n; i++) cin>>a[i];
    int l = 1;
    int r = n;
    int sumLeft = a[1];
    int sumRight = a[n];
    while(l<r){
        if(sumLeft < sumRight){
            l++;
            sumLeft += a[l];
        }else if(sumRight < sumLeft){
            r--;
            sumRight += a[r];
        }
        if(sumLeft == sumRight) break;
    }
    cout<<l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CHIAMANG.INP", "r", stdin);
    freopen("CHIAMANG.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
