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

string str;


void solve(){
    // Something goes here...
    cin>>str;
    int tmp = 0;
    int ans = 0;
    for(char c: str){
        if(c != 'D'){
            if(tmp == 0){
                tmp = c - '0';
            }else{
                tmp *= 10;
                tmp += c - '0';
            }
        }else{
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    cout<<ans;
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
