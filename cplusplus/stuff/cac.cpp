#include <iostream>
using namespace std;

int main(){
    long long tmp;
    long long ans = -1e9+7;
    for(int i = 0; i<5; i++){
        cout<<"Input "<<i+1<<"th number: ";
        cin>>tmp;
        ans = max(ans, tmp);
    }
    cout<<ans;
}
