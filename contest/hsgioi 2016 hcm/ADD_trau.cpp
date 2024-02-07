/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define N 300005
#define pii pair<int,int>
#define int long long
#define endl "\n"
using namespace std;

string s;
string firstHalf, secondHalf;

bool add(string s1, string s2){
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = secondHalf.length();
    if(len1 < 1e19 && len2 < 1e19 && len3 < 1e19){
        int tmp1 = stoll(s1);
        int tmp2 = stoll(s2);
        int tmp3 = stoll(secondHalf);
        return (tmp1 + tmp2) == tmp3;
    }else{
        return false;
    }
}

void solve(){
    cin>>s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] != '='){
            firstHalf += s[i];
        }else{
            secondHalf = s.substr(i+1);
            break;
        }
    }
    int ans = -1;
    string tmp, tmp2;
    for(int i = 0; i<firstHalf.length(); i++){
        tmp += firstHalf[i];
        tmp2 = firstHalf.substr(i+1);
        if(add(tmp, tmp2)){
            ans = i;
            break;
        }
    }
    if(ans != -1) cout<<tmp<<"+"<<tmp2<<"="<<secondHalf;
    else cout<<s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ADD.INP", "r", stdin);
    freopen("ADD.OUT", "w", stdout);
    solve();
}
