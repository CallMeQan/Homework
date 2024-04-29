/*
    author: Qan
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 2;

bool loopInput = false;

int k, n, longest;
int tracked = 0;
// Add xong cap nhat lai doan dai nhat
map<int, pair<int, int>> mapp;

vector<pair<int, int>> ans;

vector<pair<int,int>> tmp;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.se < b.se;
}

void update(){
    int temp = longest;
    sort(tmp.begin(), tmp.end(), cmp);
    int previousVal = 1;
    for(auto v: tmp){
        longest = max(longest, v.se - previousVal + 1);
        previousVal = v.se;
    }
}

void solve(){
    // Something goes here...
    cin>>k>>n;
    for(int i = 1;i<=n; i++){
        int l, r;
        cin>>l>>r;
        mapp[l].fi = i;
        mapp[l].se++;
        mapp[r+1].fi = i;
        mapp[r+1].se--;
    }
    longest = k;
    for(int i = 1;i<=n; i++){
        int idd = mapp[i].fi;
        int state = mapp[i].se;
        if(state < 0){
            //Xoa
            pair<int,int> take;
            for(auto v: tmp){
                if(v.fi == idd){
                    take = {idd, v.se};
                    break;
                }
            }
            auto it = find(tmp.begin(), tmp.end(), take);
            tmp.erase(it);
            ans.push_back(take);
            update();
        }else if(state > 0){
            //Them
            int pos;
            if(longest % 2 != 0) pos = longest/2 + 1;
            else pos = longest / 2;
            tmp.pb({idd, pos});
            longest = 0;
            update();
        }
    }
    for(auto v: ans){
        cout<<v.se<<" ";
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
