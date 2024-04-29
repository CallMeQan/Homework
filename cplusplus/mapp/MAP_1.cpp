#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, q;
map<int,int> a;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        a[num]++;
    }
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<a[num]<<endl;
    }
}
