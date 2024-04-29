#include <bits/stdc++.h>
#include <string>
#define int long long
#define endl '\n'
using namespace std;

int n, q;
map<int,string> a;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++){
        int num;
        cin>>num;
        a[num] += to_string(i) + ' ';
    }
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        if(a[num] == "" || a[num] == " "){
            cout<<-1<<endl;
        }else cout<<a[num]<<endl;
    }
}

