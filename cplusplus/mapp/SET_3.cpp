#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

int q;
multiset<int> ds;

char type;
int x;

void solve(){
    // Something goes here...
    cin>>q;
    while(q--){
        cin>>type;
        if(type == '+'){
            cin>>x;
            ds.insert(x);
        }else if(type == '-'){
            cin>>x;
            if(ds.find(x) != ds.end()){
                ds.erase(ds.find(x));
            }
        }else{
            cin>>x;
            if(ds.empty()){
                cout<<"-1 -1 -1 -1"<<endl;
            }else{
                auto a = ds.lower_bound(x);
                if(a == ds.begin()){
                    cout<<"-1 ";
                }else{
                    a--;
                    cout<<*a<<' ';
                }
                auto b = ds.upper_bound(x);
                if(b == ds.begin()){
                    cout<<"-1 ";
                }else{
                    b--;
                    cout<<*b<<' ';
                }

                auto c = ds.lower_bound(x);
                if(c == ds.end()) cout<<"-1 ";
                else cout<<*c<<" ";

                auto d = ds.upper_bound(x);
                if(d == ds.end()) cout<<"-1\n";
                else cout<<*d<<"\n";
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
