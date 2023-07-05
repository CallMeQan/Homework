#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long long n) {
    long long root = sqrt(n);
    return root * root == n;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long x,y;
    long long count = 0;
    cin>>x>>y;
    long long root_x = sqrt(x);
    long long root_y = sqrt(y);
    //https://www.youtube.com/watch?v=hQAG7BoXqYU
    if(isPerfectSquare(x)) cout<<root_y-root_x+1;
    else cout<<root_y-root_x;
}