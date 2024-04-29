
#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

bool loopInput = false;

int q;
multiset<int> a;

char type;
int x;

void solve(){
    // Something goes here...
    cin>>q;
    while(q--){
        cin>>type>>x;
        if(type == '+'){
            a.insert(x);
        }else if(type == '-'){
            if(a.find(x) != a.end()){
                a.erase(a.find(x));
            }
        }else{
            if(a.find(x) != a.end()){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }
    }
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
