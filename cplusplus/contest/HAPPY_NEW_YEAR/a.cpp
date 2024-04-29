/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool loopInput = false;

int n;
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    n *= 2024;
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(i*i == n){
                count++;
            }else{
                count+=2;
            }
        }
    }
    cout<<count;
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