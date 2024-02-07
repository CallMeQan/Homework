#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+5;

int n, m;
int a[N];
map<int,int> mapp;

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int cur = 1;
    while(m>0){
        int tmp = a[cur];
        for(int i = 1; i<=n; i++){
            if(cur == i) continue;
            if(tmp + a[i] <= m){

            }
        }
        cur++;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
