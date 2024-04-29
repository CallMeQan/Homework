#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int N = 1e6+5;
int n;
int a[N];
vector<pii> s;

void printset(){
    for(auto v: s) cout<<v.first<<" "<<v.second<<endl;
    cout<<"=PRINT SET DONE="<<endl;
}
void printArray(int what[]){
    for(int i = 0; i<sizeof(what); i++) cout<<what[i]<<endl;
    cout<<"=PRINT ARRAY DONE="<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("SAPXEP.INP", "r", stdin);
    freopen("SAPXEP.OUT", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n; i++){
        cin>>a[i];
        s.push_back({a[i], i});
    }
    sort(s.begin(), s.end());
    //printset();
    int b[n+2];
    fill(b+1, b+n+1, 0);
    int q = n+1;
    while(q-- && q > 0){
        //cout<<"====== THIS IS q = "<<q<<endl;
        int ans = 0;
        if(q % 2 == 0){
            // Buoc chan
            auto se = s.end();
            se--;
            pair<int,int> pos = *se;
            for(int i = n; i>=1; i--){
                if(!b[i]){
                    b[i] = pos.first;
                    ans += abs(pos.second - i);
                    s.pop_back();
                    //printArray(b);
                    break;
                }
            }
            //printset();
        }else{
            // Buoc le
            auto fi = s.begin();
            pair<int,int> val = *fi;
            for(int i = 1; i<= n; i++){
                if(!b[i]){
                    b[i] = val.first;
                    ans += abs(val.second - i);
                    s.erase(fi);
                    //printArray(b);
                    break;
                }
            }
            //printset();
        }
        cout<<ans<<endl;
    }

}
