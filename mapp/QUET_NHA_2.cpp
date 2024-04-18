/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 2;

bool loopInput = false;

int n;

map<int,int> mapp;

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1;i<=n; i++){
        int l, r;
        cin>>l>>r;
        mapp[l]++;
        mapp[r]--;
    }
    int sum = 0;
    int ans = 0;
    int pos = -1;
    for(auto i: mapp){
        sum += i.second;
        if(ans < sum){
            ans = sum;
            pos = i.first;
        }
    }
    cout<<pos<<" "<<ans;
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
