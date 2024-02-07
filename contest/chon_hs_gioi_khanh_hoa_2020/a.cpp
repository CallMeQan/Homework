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

int n, k;
int cnt[10];

void solve(){
    // Something goes here...
    cin>>n>>k;
    if(9*n < k){
        cout<<-1;
        return;
    }
    for(int i = 1; i<=n; i++){
        if(k - 9 >= 0){
            k-=9;
            cnt[9]++;
        }else if(k-8 >= 0){
            k-=8;
            cnt[8]++;
        }else if(k-7 >= 0){
            k-=7;
            cnt[7]++;
        }else if(k-6 >= 0){
            k-=6;
            cnt[6]++;
        }else if(k-5 >= 0){
            k-=5;
            cnt[5]++;
        }else if(k-4 >= 0){
            k-=4;
            cnt[4]++;
        }else if(k-3 >= 0){
            k-=3;
            cnt[3]++;
        }else if(k-2 >= 0){
            k-=2;
            cnt[2]++;
        }else if(k-1 >= 0){
            k-=1;
            cnt[1]++;
        }
        if(k==0) break;
    }
    for(int i = 9; i>=1; i--){
        while(cnt[i] > 0){
            cout<<i;
            cnt[i]--;
            n--;
        }
    }
    while(n>0) {
        cout<<0;
        n--;
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