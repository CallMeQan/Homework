/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
int N = 1e6 + 9;

bool multiTestCases = true;

int n;
int cur = 1;

void solve(int x, int y){
    cout<<x<<" "<<y<<" "<<cur<<endl;
    cur++;
    if(cur > N) cur = 1;
}

void loop(){
    // Something goes here...
    cin>>n;
    if(n%2==0){
        N = n/2;
    }else{
        N = (n/(int)2)+1;
    }
    while(true){
        int x, y;
        cin>>x>>y;
        if(x == 0 && y == 0){
            cout<<"0 0 0"<<endl;
            break;
        }
        solve(x,y);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    loop();
}