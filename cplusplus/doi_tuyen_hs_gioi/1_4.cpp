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
array<int> so;

void dequy(int length, int s){
    if(length == 15){
        if( s ==0){
            return;
        }
        so.pb(s);
        return;
    }
    dequy(length+1, s*10);
    dequy(length+1, s*10+2);
    dequy(length+1, s*10+7);
    
}

void solve(){
    cin>>n;
    for(auto x:so){
        if(x>=n & x%n==0){
            cout<<x<<endl;
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dequy(0,0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}