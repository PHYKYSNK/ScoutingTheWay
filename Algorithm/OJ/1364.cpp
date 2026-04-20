#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

ll func(ll n,ll m) {
    if(n == 1 || m == 1) {
        return 1;
    }
    else if(n < 1 || m < 1) return 1;
    else if(n < m) {
        return func(n,n);
    }
    return func(n,m-1) + func(n-m,m);
}
void solve() {
    ll n,m;cin>>n>>m;
    ll ans = func(n,m);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;cin>>_;while(_--)
    solve();
    return 0;
}