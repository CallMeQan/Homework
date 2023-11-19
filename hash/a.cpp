/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

string a, b;

void solve(){
    // Something goes here...
    cin>>a>>b;
    
    for(int i = 0; i<a.length(); i++){
        int flagged = 0;
        for(int j = i; j<(i+b.length()); j++){
            int z = j - i;
            if(a[j]){
                if(a[j] == b[z]){
                    cout<<i+1<<" ";
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}