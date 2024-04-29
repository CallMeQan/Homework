#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5+5;

int n, m;
int a[N];
map<int,int> mapp;
set<int> ds;

void solve(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        mapp[a[i]]++;
    }
    int ans = 0;
    vector<int> remains;
    for(int i = 1; i<=n; i++){
        if(mapp[m-a[i]] > 0){
            mapp[m-a[i]]--;
            mapp[a[i]]--;
            ans++;
        }else{

        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
