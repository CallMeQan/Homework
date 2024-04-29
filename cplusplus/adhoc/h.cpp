/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

string n;
int ans = 0;
int a[N];

void solve(){
    // Something goes here...
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
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}