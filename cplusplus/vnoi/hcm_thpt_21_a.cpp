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

void solve(){
    // Something goes here...
    cin>>n;
    int page = -1;
    int count = 0;
    for(int i = 4; i<=10000; i++){
        int tmp = i;
        while(tmp != 0){
            count++;
            tmp /= 10;
        }
        if(count == n){
            page = i;
            break;
        }
    }
    cout<<page;
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