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
        mapp[r+1]--;
    }
    int sum = 0;
    int ans = 0;
    int cnt = 0;
    bool check = false;
    for(auto v: mapp){
        sum += v.second;
        if(check == true)
        {
            check = false;
            cnt += (v.first - 1);
        }
        if(ans < sum)
        {
            ans = sum;
            check = true;
            cnt = -(v.first - 1);
        }
        else if(ans == sum)
        {
            check = true;
            cnt = cnt - (v.first - 1);
        }

    }
    cout<<ans<<endl;
    cout<<cnt<<endl;
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
