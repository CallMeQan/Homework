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
 
int n;
int a[N];
 
void solve(){
    // Something goes here...
    int a, b, c;
    cin>>a>>b>>c;
    for(int i=1; i<=3; i++){
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
    }
    cout<<b;
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