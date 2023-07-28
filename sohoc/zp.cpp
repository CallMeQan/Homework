/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = true;

int a[N];

int count_divisors(int num)
{
    int count = 0;
    for (int i = 1; i <= sqrt(num); i++){
        if (num % i == 0){
            count++;
            if (i != num / i) count++;
        }
    }

    return count;
}

int maxNum = -1;

void solve(int index){
    // Something goes here...
    cin>>a[index];
    maxNum = max(maxNum, count_divisors(a[index]));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        for(int i = 1; i <= t; i++) solve(i);
        cout<<maxNum;
    } else solve(0);
}