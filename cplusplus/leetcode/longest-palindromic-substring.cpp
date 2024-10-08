/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string expand(int l, int r, string s){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l--;
        r++;
    }
    return s.substr(l+1, r - l - 1);
}

string solve(string s){
    string ans = "";
    int n = s.size();
    for(int i = 0; i<n; i++){
        string odd = expand(i, i, s);
        if(odd.size() > ans.size()){
            ans = odd;
        }

        string even = expand(i, i+1, s);
        if(even.size() > ans.size()){
            ans = even;
        }
    }
    return ans;
}

signed main(){
    fast;
    string s;
    cin>>s;
    cout<<solve(s);
}
