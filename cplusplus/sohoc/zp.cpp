/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 2000006
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

int n, k, cnt[N], res = 0;
void sanguoc(int t){
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            cnt[j]++;
        }
    }
}

int maxNum = -1;

void solve(){
    // Something goes here...
    cin >> n;
    sanguoc(n);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        res = max(res, cnt[x]);
    }
    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
    } else solve();
}