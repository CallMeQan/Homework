#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e5+5;

int n, m;
string a[N];

bool cmp(string &a, string &b){
    int aLength = a.size();
    int bLength = b.size();
    if(a[0] != '-' && b[0] != '-'){
        //All positive
        if(aLength == bLength){
            return a > b;
        }
        return aLength > bLength;
    }
    if(a[0] == '-' && b[0] == '-'){
        //All negative
        if(aLength == bLength){
            return a < b;
        }
        return aLength < bLength;
    }
    if(a[0] == '-'){
        //Only a negative
        return false;
    }else return true;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i<=n; i++) {
        cout<<a[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

