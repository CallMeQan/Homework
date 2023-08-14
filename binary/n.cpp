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

int n, k;
int a[N], pre[N], suf[N];

void solve(){
    // Something goes here...
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    pre[1] = a[1];
    for(int i = 2 ; i <= n ; i++)
        pre[i] = __gcd(pre[i - 1] , a[i]);
    // n * log2(10 ^ 9)
    suf[n] = a[n];
    for(int i = n - 1 ; i >= 1 ; i--)
        suf[i] = __gcd(suf[i + 1] , a[i]);
    // n * log2(10 ^ 9)
 
    int maxi = 0;
    for(int l = 1 ; l <= n ; l++)
    {
        int r = l + k - 1;
        if(r <= n)
            maxi = max(maxi , __gcd(pre[l - 1] , suf[r + 1]));
        // l = 3, k = 4 -> r = 3 + 4 - 1 = 6, 3,4,5,6
    }
    // n * log2(10 ^ 9)
    cout << maxi;
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