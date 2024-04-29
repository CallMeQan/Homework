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

int n,m,k;
int r1 = 0;
int r2 = 0;
int a[N], first[N], second[N];

void solve(){
    // Something goes here...
    /*
        6 11 3
        1 2 9 15 7 11
    */
    cin>>n>>k>>m;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        if(a[i] % m == 0){
            first[++r1] = a[i];
        }else{
            second[++r2] = a[i];
        }
    }
    sort(first+1, first + r1 + 1);
    for (int i = 1; i <= r1; i++)
    {
        int cuts = first[i] / m;
        if(k>=cuts){
            ans += cuts - 1;
            k -= cuts;
        }else{
            ans+=k;
            k = 0;
        }
    }
    if(k>0){
        for(int i = 1; i<= r2; i++){
            int cuts = second[i] / m;
            if(k>=cuts){
                ans += cuts;
                k -= cuts;
            }else{
                ans+=k;
                k = 0;
            }
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