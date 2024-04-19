/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 2e5 + 9; // n * k <= 2e5

bool multiTestCases = true;

/*
4 4
1 2 3 4 base
2 3 1 4
3 2 1 4
4 2 3 1

[1]{
    [1]{},
    [2]{2, 3},
    [3]{3, 4},
    [4]{4, 5}
}

[2]{
    [1]{3, 4},
    [2]{2, 3},
    [3]{3, 4, 2, 3},
    [4]{4, 5, 4, 5}
}

[3]{
    [1]{3, 4, 3, 4},
    [2]{2, 3, 2, 3},
    [3]{3, 4, 2, 3},
    [4]{4, 5, 4, 5, 4, 5}
}
[4]{
    [1]{3, 4, 3, 4, 4, 5},
    [2]{2, 3, 2, 3, 2, 3},
    [3]{3, 4, 2, 3, 3, 4},
    [4]{4, 5, 4, 5, 4, 5}
}
- - - - -
1 2 3 4 5
skip pos 1 because we counting on 2
=> 4 must be on 4 or 5
=> 3 must be on 3 or 4
=> 2 must be on 2 or 3
=> 1 must be on 3 or 4
=> 2 3 1 4

Actual order: 2 3 1 4
*/

void solve(){
    // Something goes here...
    int n, k;
    cin>>n>>k;
    vector<vector<int>> possibles(n+9);
    vector<pair<int,int>> cnt(n+9, {-1, -1});
    bool flag = false;
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            int num;
            cin>>num;
            num--;
            if(!flag){
                if(j == 1) continue;
                // Skip first pos cuz it not important
                if(i == 0){
                    possibles[num].push_back(j);
                    possibles[num].push_back(j+1);
                }else{
                    if(possibles[num].empty()){
                        possibles[num].push_back(j + 1);
                        possibles[num].push_back(j);
                    }else{
                        if(possibles[num].size() == 2){
                            if(possibles[num][1] != j && possibles[num][1] != j + 1){
                                possibles[num].pop_back();
                            }
                        }
                        if(possibles[num][0] != j && possibles[num][0] != j + 1){
                            possibles[num].erase(possibles[num].begin());
                        }
                        if(possibles[num].empty()){
                            flag = true;
                        }else if(possibles[num].size() == 1){
                            if (cnt[possibles[num][0]].first != -1 && cnt[possibles[num][0]].second != num) flag = true;
                            cnt[possibles[num][0]] = {possibles[num][0], num};
                        }
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }else cout<<"YES"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}