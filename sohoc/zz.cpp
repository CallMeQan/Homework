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

void solve(){
    // long long can hold 19 digits max
    int n;
    cin>>n;
    int theThing = 2 * 3 * 5 * 7 * 11;
	if (n < 4) cout << -1;
	else if (n == 4) cout << theThing;
	else {
        cout<<"1";
        int tracked = 1;
        for(int i = 1; i < n-4; i++) {
            cout<<"0";
            tracked = tracked * 10;
        }
        int temp = 1;
        for (int i = 1; i < n; i++)
        {
            temp = (temp*10)%theThing;
        }
        temp = theThing - temp;
        if (temp >= 1000) cout << temp;
        else if (temp >= 100 && temp < 1000) cout << '0' << temp;
        else if (temp >= 10 && temp < 100) cout << '00' << temp;
        else cout << '000' << temp;
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