#include<bits/stdc++.h>
using namespace std;

string s[20000];
int n,cnt;
map<string,int> D;
set<string> ds;
string t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        D[s[i]]++;
    }
    for(int i=1; i<=n; i++){
        for(int st=1; st<=s[i].size(); st++){
            t.clear();
            for(int j=st; j<=s[i].size(); j++){
                t+=s[i][j-1];
                ds.insert(t);
            }
        }
        cnt=0;
        for(string v: ds){
            cnt+=D[v];
        }
        cout<<cnt-1<<'\n';
        ds.clear();
    }




    return 0;
}
