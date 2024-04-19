#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const string NAME = "SAMPLE";
const int NTEST = 10;
const string NAME_EXE = NAME+".exe";
const string NAME_TRAU_EXE = NAME+"_trau.exe";
const string NAME_INP = NAME+".INP";
const string NAME_OUT = NAME+".OUT";
const string NAME_ANS = NAME+".ANS";
const string FILE_COMPARE = "fc "+NAME_OUT+" "+NAME_ANS;

int Rand(int l, int r){
    assert(l<=r);
    return l + rd() % (r-l+1);
}

void gentest(){
    ofstream inp (NAME_INP.c_str());
    int n = Rand(1, 3e4);
    int m = Rand(1, 3e4);
    inp<<n<<" "<<m<<endl;
    for(int i = 1; i<=n; i++){
        int p = Rand(1, 1e5);
        int v = Rand(1, 1e5);
        inp<<p<<" "<<v<<endl;
    }
    for(int i = 1; i<=m; i++){
        int c = Rand(1,100000);
        inp<<c<<endl;
    }
    inp.close();
}

signed main(){
    srand(time(NULL));
    for(int i = 1; i<=NTEST; i++){
        gentest();
        system(NAME_EXE.c_str());
        system(NAME_TRAU_EXE.c_str());
        if(system(FILE_COMPARE.c_str()) != 0){
            cout<<"Test "<<i<<": WA"<<endl;
            return 0;
        }
        cout<<"Test "<<i<<": O-KK"<<endl;
    }
}
