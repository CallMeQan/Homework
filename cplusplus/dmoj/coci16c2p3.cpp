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

int n;
int a[N];
int ans = 0;

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    a[0] = 0;
    int l = 1;
    int r = n;
    while(l <= r){
        //cout<<a[l]<<" "<<a[r]<<endl;
        if(a[l] == a[r]){
            l++;
            r--;
        }else if(a[l] > a[r]){
            a[r-1] = a[r-1] + a[r];
            r--;
            ans++;
        }else if(a[l] < a[r]){
            a[l+1] = a[l+1] + a[l];
            l++;
            ans++;
        }
        //cout<<"====="<<endl;
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