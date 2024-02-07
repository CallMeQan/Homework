#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
int a[1005][1005];
bool atLeast = false;
bool allAbove0 = true;
bool alAboveSum = false;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TROICHEO.INP", "r", stdin);
    freopen("TROICHEO.OUT", "w", stdout);
    int ans = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j] < 0) {
                allAbove0 = false;
            }
        }
    }
    if(!allAbove0){
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i = 1; i<=n; i++){
        int tmp = 0;
        for(int j = 1; j<=n; j++){
            if(j == i) continue;
            tmp += a[i][j];
        }
        if(a[i][i] > tmp) {
            atLeast = true;
            ans++;
        }else if(a[i][i] >= tmp) allAbove0 = true;
    }
    if(atLeast && allAbove0) {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;
}

