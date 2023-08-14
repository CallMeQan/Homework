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

int n, m;
int a[N];
map<int, int> mp;
void solve(){
    mp[0] = 1;
    cin>>n>>m;
    int ans = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int num;
        cin>>num;
        sum += num;
        sum %= m;
        ans += mp[sum];
        mp[sum]++;
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