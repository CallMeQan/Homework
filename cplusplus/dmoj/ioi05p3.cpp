/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

bool loopInput = false;

int n;

struct node{
    int lazy;
    int value;
    int l, r, mid, high, id, range_;
    vector<node> child;

    node(int l_=1, int r_=n, int lazy_=0, int id_=0, int value_=0, int high_=0){
		
		value=value_, high=high_, l=l_, r=r_, lazy=lazy_, id=id_;
		
		mid = (l + r) / 2;
        range_ = r - l + 1;
	}

    void push(){
        if(child.empty() && r > l){
            // Không có cây con nhưng vẫn còn trong đoạn [...] nên tạo thêm
            child.push_back(node(l, mid));
		    child.push_back(node(mid + 1, r));
        }

        if(id != 0){
            // Bằng cách nào đó, nó vẫn lấy id và lỗi nên check tránh nó
            if(r > l){
                child[0].lazy = child[1].lazy = lazy;
				child[0].id = child[1].id = id;
            }
            value = high = range_ * lazy;
        }
        lazy = id = 0;
    }

    int get(int h){
        push();
        if(l == r){
            if(high > h) return l - 1;
			return l;
        }
        child[0].push();
        if(child[0].high > h) return child[0].get(h);
		return child[1].get(h - child[0].value);
    }

    void update(int a, int b, int D){
        push();
        if(a > r || b < l) return;
		if(b >= r && a <= l){
			lazy =D; // dick emoji
			id = 1;
			push();
			return;
		}
        if(child.empty()) return;
        child[0].update(a,b,D);
        child[1].update(a,b,D);

        value = child[0].value + child[1].value;
        high = max(child[0].high, child[0].value + child[1].high);
    }
};

void solve(){
    // https://usaco.guide/CPH.pdf#page=271
    node segment;
    char type;
	
	while(cin>>type && type!='E'){
		
		if(type=='Q'){
			int h;
			cin >> h;
			cout << segment.get(h) << endl;
		}
		
		if(type=='I'){
			int a, b, d;
			cin >> a >> b >> d;
			segment.update(a,b,d);
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}