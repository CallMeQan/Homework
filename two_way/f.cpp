/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1006
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
int a[N][N];

void solve(){
    // Something goes here...
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0; // bien1
    int ans4 = 0; // bien2
    int ans5 = 0; //top
    int ans6 = 0; //bot
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n; j++){
            int num;
            cin>>num;
            a[i][j] = num;
            if(i==j) ans1 += num;
            if(j==1) ans3 += num;
            if(j==n) ans4 += num;
            if(i==1) ans5 += num;
            if(i==n) ans6 += num;
        }
    }
    for(int i = n; i>=1; i--){
        ans2 += a[i][n - i + 1];
    }
    int total = (ans1+ans2+ans3+ans4+ans5+ans6) - (a[1][1] *2 + a[1][n]*2 + a[n][1]*2 + a[n][n]*2);
    if(n%2 != 0){
        int b = (n+1)/2;
        total -= a[b][b];
    }
    cout<<total;
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