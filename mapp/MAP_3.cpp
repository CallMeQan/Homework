#include <bits/stdc++.h>
#include <string>
#define int long long
#define endl '\n'
using namespace std;

int n, q;
int a[200005];
map<int,vector<int>> mapp;

int bs(int x , int pos)
{
    int l = 0, r = mapp[x].size() - 1, ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(mapp[x][mid] <= pos){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    return ans + 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        mapp[a[i]].push_back(i);
    }

    cin>>q;
    while(q--){
        int l, r, x;
        cin>>l>>r>>x;
        if(mapp[x].size() == 0){
            cout<<"0"<<endl;
        }else{
            cout<<bs(x, r) - bs(x, l - 1)<<endl;
        }
    }
}

