#include<bits/stdc++.h>
using namespace std;
 
const long long N = 1e5 + 3;
long long k,n;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for(long long i = 1 ; i <= k ; i++){
        long long maxNum = 0;
        cin >> n;
        long long cnt[N] = {0};
        long long a[N] = {0};
        for(long long j = 1 ; j <= n ; j++)
        {
            cin >> a[j];
            cnt[a[j]]++;
            maxNum = max(maxNum, a[j]);
        }
        bool flagged = false;
        for (long long j = maxNum; j >= 1; j--)
        {
            if(cnt[j] >= 2){
                cnt[j] = cnt[j] - 2;
                for (long long g = j; g >=1 ; g--)
                {
                    if(cnt[g] >= 2){
                        cout<<j*g<<"\n";
                        flagged = true;
                        break;
                    }
                }
            }
            if(flagged) break;
        }
        if(!flagged) cout<<"-1\n";
    }
    return 0;
}