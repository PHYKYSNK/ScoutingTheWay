#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
#define endl "\n"
#define all(x) (x).begin(),(x).end()

db qpow(db x,ll n) {
    //x的-n次方 == (1.0/x)的n次方
    if(n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    db ans = 1;
    while(n) {
        if(n & 1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }
    return ans;
}
void solve() {
    db x,n;cin>>x>>n;
    cout<<fixed<<setprecision(5)<<qpow(x,(ll)n)<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}