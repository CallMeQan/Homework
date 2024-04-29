/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 6000006
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

int n;
int a[N];
bool cnt[N];
void solve(){
    // Something goes here...
    int ans = N;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        cnt[a[i]] = true;
        bool l;
        if(a[i] == 1) l = true;
        else l = cnt[a[i]-1];
        bool r = cnt[a[i]+1];
        if(l == false && (a[i] -1)<ans) ans = a[i]-1;
        else if(l == true && r == false && (a[i]+1) < ans) ans = a[i]+1;
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