/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string s;
int solve(){
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '['){
            cnt++;
        }else{
            // This is if for closing bracket
            if(cnt > 0) cnt--;
        }
    }
    return (cnt + 1)/2;
}

signed main(){
    fast;
    cin>>x;
    cout<<solve();
}
