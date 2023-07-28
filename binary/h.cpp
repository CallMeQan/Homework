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
#define arr vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n, m;
int p[N];
int a[N], b[N];

int binarySearch(int l, int r, int target){
    int ans = -1;
    while (l <= r){
        int m = (r+l)/2;
        if(b[m] >= target){
            ans = m;
            r=m-1;
        }
        else l = m + 1;
    }
    return ans;
}

void solve(){
    b[0] = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>p[i];
        cout<<binarySearch(1, n, p[i])<<" ";
    }
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