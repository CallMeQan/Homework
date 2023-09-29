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
string s;
int cntmo = 0;
int cntdong = 0;
void solve(){
    // Something goes here...
    int ans = 0;
    cin>>n>>s;
    for(int i = 1; i<=n; i++){
        if(s[i] == '('){
            ans++;
        }else{
            if(ans == 0){
                cntmo++;
            }else{
                ans--;
            }
        }
    }
    while(cntmo>0){
        cout<<"(";
        cntmo--;
    }
    while(ans<0){
        cout<<")";
        ans++;
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