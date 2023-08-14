#include<bits/stdc++.h>
using namespace std;
#define long long long
const long N=1e5+10;
 
long n,A[N],sum[N],L,R,ans;
multiset<long> ds;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>L>>R;
    for(long i=1; i<=n; i++) cin>>A[i];
    for(long i=1; i<=n; i++){
        sum[i]=A[i]+sum[i-1];
    }
    ans=-1e18;
    for(long i=1; i<=n; i++){
        if(i>=L){
            ds.insert(sum[i-L]);
        }
        if(i>R){
            ds.erase(ds.find(sum[i-R-1]));
        }
        if(!ds.empty()) ans=max(ans,sum[i]-*ds.begin());
    }
    cout<<ans;
 
    return 0;
}