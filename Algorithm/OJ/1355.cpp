/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

vector<ll> node;

bool ismirror(int a,int b) {
    if(a >= node.size() && b >= node.size()) {
        return true;
    }
    if(a >= node.size() || b >= node.size()) {
        return false;
    }
    if(node[a] != node[b]) {
        return false;
    }
    return ismirror(a*2,b*2+1) && ismirror(a*2+1,b*2);
}
void solve() {
    ll h;
    cin >> h;
    
    ll n = (1LL << h) - 1;//总节点
    node.resize(n+1);
    for(int i=1;i<=n;i++) {
        cin >> node[i];
    }
    if(ismirror(1,1)) {
        cout << "true";
    }
    else cout << "false";
}
int main() {
    solve();
    return 0;
}