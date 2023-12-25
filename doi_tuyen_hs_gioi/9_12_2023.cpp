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
const int N = 1e5 + 9;

bool multiTestCases = false;

int n,k;
int a[N];
int cnt[N];

bool check(vector<int> bruh, int num){
    for(auto i: bruh){
        if(i==num) return true;
    }
    return false;
}

void solve(){
    // Something goes here...
    cin>>n>>k;
    int r = k;
    for(int i = 1 ; i<=n; i++){
        cin>>a[i];
    }
    int l = 1;
    int ans = 0;
    while(l<=r){
        bool flag = false;
        int cnt[N];
        vector<int> unqiueNum;
        for(int i = l; i<=r; i++){
            cnt[a[i]]++;
            if(!check(unqiueNum, a[i])){
                unqiueNum.push_back(a[i]);
            }
        }
        for(auto i: unqiueNum){
            if(cnt[i] != k){
                flag = true;
                break;
            }
        }
        if(flag){

        }else{

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