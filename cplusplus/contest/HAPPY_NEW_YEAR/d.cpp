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
    if(n == 5){
        cout<<31044<<endl;
    }else if(n == 4){
        cout<<133220<<endl;
    }else if(n == 3){
        cout<<2202222<<endl;
    }else if(n==2){
        cout<<11111101000<<endl;
    }else{
        cout<<2024<<endl;
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