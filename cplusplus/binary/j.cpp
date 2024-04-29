/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n;
pair<int, int> a[N];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

void solve(){
    int l, r, mid, pos, ans = 0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++){
        l=1;
        r=i;
        while(l<=r){
            mid=(l+r)/2;
            if(a[mid].second>a[i].first){
                pos=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=ans+i-pos;
    }
    cout<<ans;
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