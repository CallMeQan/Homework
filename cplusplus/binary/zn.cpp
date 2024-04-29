/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1002
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

int m, n;
int a[N][N] = {0};
int pre[N][N] = {0};

int getSum(int i1, int j1, int i2, int j2) {
	return pre[i2][j2] - pre[i1-1][j2] - pre[i2][j1-1] + pre[i1-1][j1-1];
}

pair<int, int> binarySearch(int i, int j, int i2, int j2){
    int res = 1e18;
    int res1, res2;
    int sum = getSum(i, j, i2, j2);
    int l = 1, r = n;
    while(l <= r){
        // Bruh copilot, wtf is this
        int mid = (l + r) / 2;
        int sum1 = getSum(i, j, i2, mid);
        int sum2 = sum - sum1;
        if(res > abs(sum1 - sum2)){
            res = abs(sum1 - sum2);
            res1 = sum1;
            res2 = sum2;
        }
        if(sum1 < sum2) l = mid + 1;
        else if(sum1 > sum2) r = mid - 1;
        else break;
    }
    return {res1, res2};
}

void solve(){
    int res = 1e18;
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            pre[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - pre[i-1][j-1];
            a[i][j] = pre[i][j];
        }
    }

    for(int i = 1; i < m; i++){
        pair<int,int> x1 = binarySearch(1,1, i, n);
        pair<int,int> x2 = binarySearch(i+1, 1, m, n);
        res = min(res, max({x1.fi, x1.se, x2.fi, x2.se}) - min({x1.fi, x1.se, x2.fi, x2.se}));
    }
    cout<<res;
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