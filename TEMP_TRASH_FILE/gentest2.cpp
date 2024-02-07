#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int NTEST = 0;
const string NAME_FILE = "";

int Rand(int l, int r){
    assert(l<=r);
    return l + rd() % (r-l+1);
}

void gentest(){
    ofstream inp((NAME_FILE + ".INP").c_str());
    int n = Rand(1, 1e6);
    inp<<n<<'\n';
    for(int i= 1; i<=n; i++) inp<<Rand(1,1e4)<<'\n';
    inp.close();
}

signed main(){
    srand(time(NULL));
    for(int i=1; i<=NTEST; i++){
        gentest();
        system((NAME_FILE + "exe").c_str());
        system((NAME_FILE + "_trau.exe").c_str());

        int flag = system(("fc "+NAME_FILE+".OUT "+NAME_FILE+".ANS").c_str());
        if(flag != 0){
            cout<<"TEST "<<i<<": WA"<<endl;
            return 0;
        }
        cout<<"TEST "<<i<<":O-OKEEE"<<endl;
    }
}
