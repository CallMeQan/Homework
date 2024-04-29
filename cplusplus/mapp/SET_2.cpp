
#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

int q;
multiset<int> a;

char type;
int x;

void solve(){
    // Something goes here...
    cin>>q;
    while(q--){
        cin>>type;
        if(type == '+'){
            cin>>x;
            a.insert(x);
        }else if(type == '-'){
            cin>>x;
            if(a.find(x) != a.end()){
                a.erase(a.find(x));
            }
        }else{
            if(a.empty()){
                cout<<"-1 -1 -1 -1"<<endl;
            }else if(a.size() == 1){
                cout<<*a.begin()<<" "<<-1<<" "<<*a.rbegin()<<" "<<-1<<endl;
            }else{
                auto v = a.end();
                v--;
                cout<<*a.begin()<<" "<<*(++a.begin())<<" "<<*v<<" "<<*(--v)<<endl;
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