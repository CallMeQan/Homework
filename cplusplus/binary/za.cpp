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

int check(int x){
    int res = 0;
    for(int i = 1; i <= m; i++){
        res += (a[i] - 1) / x + 1;
    }
    return res;
}

int binarySearch(){
    int l = 1, r = 1e18;
    int res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if (check(mid) <= n){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    return res;
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i<= m; i++) cin>>a[i];
    sort(a + 1, a + m + 1);
    cout<<binarySearch();
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