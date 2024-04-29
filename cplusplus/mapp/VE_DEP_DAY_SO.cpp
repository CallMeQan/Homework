#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,A[N],y,x,q;
map<int,int> D;
set<int> s;
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>A[i];
        D[A[i]]+=1;
    }
    for(long i=1; i<=n+1; i++){
        if(D[i]==0){
            s.insert(i);
        }
    }
    while(q--){
        cin>>x>>y;
        D[A[x]]-=1;
        if(D[A[x]]==0) s.insert(A[x]);
 
        D[y]+=1;
        if(D[y]==1) s.erase(y);
 
        cout<<*s.begin()<<'\n';
        A[x]=y;
    }
 
    return 0;
}