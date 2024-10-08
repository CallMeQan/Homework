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
    stack<char> c;
    int n = s.length();
    for(int i = 0; i<n; i++){
        if(!c.empty() && (c.top() == 'A' && s[i] == 'B') || (c.top() == 'C' && s[i] == 'D')){
            c.pop();
        }else{
            c.push(s[i]);
        }
    }
    return c.size();
}

signed main(){
    fast;
    cin>>s;
    cout<<solve();
}
