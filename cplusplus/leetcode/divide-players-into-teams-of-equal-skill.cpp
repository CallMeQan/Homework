/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> skill;
long long solve(){
    int sz = skill.size();
    if(sz == 2){
        return skill[0] * skill[1];
    }
    sort(skill.begin(), skill.end());
    int final_index = sz - 1;
    int b = 0;
    long long res = skill[b] * skill[final_index];
    long long follow = skill[b] + skill[final_index];
    b++;
    final_index--;
    while(b != final_index){
        long long sum = skill[b] + skill[final_index];
        if(sum != follow){
            res = -1;
            break;
        }else{
            res += skill[b] * skill[final_index];
        }
        b++;
        if(b == final_index)break;
        final_index--;
    }
    return res;
}

signed main(){
    fast;
    int n, num;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>num;
        skill.push_back(num);
    }
    cout<<solve();
}
