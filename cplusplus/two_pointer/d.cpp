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

string n;
int ans = 0;
int a[N];

void solve(){
    cin>>n;
    int l = 0;
    int r = (n.size() - 1);
    while(l <= r){
        if(n[l] == n[r]) {
            l++;
            r--;
        }
        else if(n[l] == 'm'){
            ans ++;
            l++;
        } else if (n[r] == 'm'){
            ans ++;
            r--;
        } else {
            cout << -1;
            return;
        }
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