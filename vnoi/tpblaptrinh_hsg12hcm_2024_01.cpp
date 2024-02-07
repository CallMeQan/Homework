#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int m;
vector<int> tuyenDuongs[75];
vector<int> stations[35];
int startS, endS,

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    for(int i = 1; i<=m; i++){
        string l;
        getline(cin, l);
        for(char c: l){
            if(isdigit(c)){
                int num = c - '0';
                tuyenDuongs[i].push_back(num);
                stations[num].push_back(m);
            }
        }
    }
    cin>>startS>>endS;
    for(int tuyenDuong: stations[startS]){
        int pos = lower_bound(tuyenDuongs[tuyenDuong].begin(), tuyenDuongs[tuyenDuong].end(), startS);
    }
}

