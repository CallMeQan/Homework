#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, m;
vector<int> connected_city[2005];
vector<int> checker[2005];
bool visited[2005];
int ans = 0;
void acs(int k){
    visited[k] = true;
    for(int city : connected_city[k]){
        if(visited[city]) {
            continue;
        }
        acs(city);
    }
}

void all_to_false(){
    for(int i = 1; i<=n; i++) visited[i] = false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        connected_city[x].push_back(y);
        // city number x is connect to city number y. Both way.
        connected_city[y].push_back(x);
    }
    for(int i = 1; i<=n; i++){
        cout<<" => Start accessing"<<i<<endl;
        acs(i);
        cout<<" => End accessing "<<i<<endl;
        for(int j = 1; j<=n; j++){
            if(!visited[j]){
                ans++;
                connected_city[i].push_back(j);
                connected_city[j].push_back(i);
            }
        }
    }
    cout<<ans;
}
