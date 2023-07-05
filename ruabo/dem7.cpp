#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
int n;
int cnta[N], cntb[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin>>x;
        cnta[x]++;
    }
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin>>x;
        cntb[x]++;
    }
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        int x;
        cin>>x;
        ans += cnta[x] * cntb[x];
    }
    cout<< ans;
    
}