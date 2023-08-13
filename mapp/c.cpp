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
map<int,int> a;
int temp[N];
void solve(){
    int ans = 0;
    cin>>n;
    if(n == 1){
        cout<<1;
        return;
    }
    for(int i = 1; i<=n; i++){
        cin>>temp[i];
        a[temp[i]]++;
    }
    for(int i = 1; i<=n; i++){
        if(a[temp[i]] == 1 && n != 1){
            ans = i;
            break;
        }
        if(a[temp[i]] == n){
            ans = 0;
            break;
        }
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