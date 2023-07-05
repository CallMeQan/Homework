/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
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

bool loopInput = false;

int n;
int a[N];

void solve(){
    // long long can hold 19 digits max
    int n;
    cin>>n;
    if (n < 4) cout << "-1";
	else if (n == 4) cout << "2310";
    else {
        if(n>19){
            int n1 = 19;
            int n2 = n-19;
            int somu = pow(10, (n1-1));
            int x = somu % 2310;
            int count = 0;
            cout<<"1";
            for(int i = 1; i<=n2; i++){
                cout<<"0";
            }
            cout<<somu + 2310 - x;
        }else{
            int somu = pow(10, (n-1));
            int x = somu % 2310;
            cout<<somu + 2310 - x;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}