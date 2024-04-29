
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n , m;
int a[N] , cnt[N], b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int answer = 0;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= m; i++){
        cin>>b[i];
        answer += cnt[b[i]];
    }
    
    cout << answer;
}