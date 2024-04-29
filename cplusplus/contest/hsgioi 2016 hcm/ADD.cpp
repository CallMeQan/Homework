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
    if(len1 < 1e18 && len2 < 1e18 && len3 < 1e18){
        int tmp1 = stoll(s1);
        int tmp2 = stoll(s2);
        int tmp3 = stoll(secondHalf);
        return (tmp1 + tmp2) == tmp3;
    }else{
        int nho = 0;
        bool flag = false;
        int cur = len3-1;
        for(int i = len1-1; i>=0; i--){
            if(i>=len2 || cur < 0) continue;
            int tmp1 = s1[i] - '0';
            int tmp2 = s2[i] - '0';
            if((tmp1 + tmp2 + nho) > secondHalf[cur])
            {
                int tmp3 = abs(tmp1-tmp2);
                while(tmp3 != 0){
                    nho++;
                    tmp3/=10;
                }
            }
            cur--;
        }
        return flag;
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
