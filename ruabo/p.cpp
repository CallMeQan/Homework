#include<bits/stdc++.h>
using namespace std;

const int n = 1e6 + 1;
int N;
int cnt[n] , a[n];

int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int maxNum = -1e6;
    int countTotal,countOdd,countEven;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        maxNum = max(maxNum, a[i]);
        if(a[i] % 2 == 0) countEven++;
        else if(a[i] % 2 == 1) countOdd++;
    }
    if(countOdd % 2 == 0){
        countTotal = C(2,countOdd) + C(2, countEven);
    }else{
        // Remove 1 odd then count odd become even, that mean the removed odd can be combine with other evens
        
    }
    cout<<countTotal;
}