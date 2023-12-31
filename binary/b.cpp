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

int n,q;
int a[N],b[N];

void solve(){
    cin>>n;
    b[0] = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    cin>>q;
    for(int i = 1; i<=q; i++){
        int x;
        cin>>x;
        int ans = -1;
        int h = n;
        int l = 1;
        while (l <= h){
            int m = l + (h-l)/2;
            if(a[m] <= x ){
                ans = a[m];
                l = m + 1;
            }else h = m - 1;
        }
        cout<<ans<<endl;
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