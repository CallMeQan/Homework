/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define INF 0x3f3f3f3f
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

int n, p;
int a[N], b[N];

int binarySearch(int l, int r, int x){
    int ans = -1;
    while (l <= r){
        int m = (l+r)/2;
        if (a[x]-b[m] >= p){
            ans = m;
            r = m-1;
        } else l = m+1;
    }
    return ans;
}

void solve(){
    //Input:
    //6 3
    //3 7 2 6 4 5
    // After sorting the c[i].se
    // 3 1 5 6 4 2
    b[0] = INF;
    cin>>n>>p;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = min(b[i-1], a[i]);
    }
    int x=0,y=0;
    for(int j = 2; j<= n; j++){
        int i = binarySearch(1, j-1, j);
        if(i != -1){
            if(j-i > y - x) {
                x = i;
                y = j;
            }
        }
    }
    if(y == 0 && x == 0) cout<<0;
    else cout<<x<<" "<<y;
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