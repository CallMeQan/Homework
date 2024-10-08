/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
using namespace std;

int x;
bool solve(){
    string str = to_string(x);
    int b = 0;
    int en = str.length() - 1;
    bool flag = true;
    while(flag){
        if(b == en || b > en){
            break;
        }
        //cout<<"Comparing "<<str[b]<<" with "<<str[en]<<endl;
        if(str[b] != str[en]){
            flag = false;
            break;
        }
        b++;
        en--;
    }
    return flag;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>x;
    cout<<solve();
}
