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

bool loopInput = false;

int k;
string s;

void solve(){
    // Something goes here...
    cin>>k>>s;
    int l = k%s.size();
    if(l == 0){
        cout<<s;
        return;
    }
	string temp;
	for(int i = l; i < s.size(); i++){
		temp += s[i+1];
	}
    string temp2;
    temp2 += s[0];
    for(int i = 0; i<l; i++){
        temp2 += s[i+1];
    }
	cout << temp+temp2;
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