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

int k;
int a[N];

void sort(int pos, string s1){
    int l = s1.length();
    for(int i = pos-1; i<l; i++){
        cout<<s1[i];
    }
    for(int i = 0; i<pos-1;i++){
        cout<<s1[i];
    }
}

void solve(){
    string s1;
    cin>>k;
    cin>>s1;
    if(k <= s1.length()){
        sort(k, s1);
        return;
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