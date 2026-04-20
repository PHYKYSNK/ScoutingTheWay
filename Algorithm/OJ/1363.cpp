#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

ll func(ll x) {
    ll re = x;
    ll bott = x;
    ll cap = x;
    while(bott >= 2 || cap >= 3) {
        ll n1 = bott / 2;
        ll n2 = cap / 3;
        ll total = n1 + n2;
        re += total;
        bott %= 2;
        bott += total;
        cap %= 3;
        cap += total;
    }
    return re;
}
void solve() {
    ll n;
    while(cin >> n) {
        ll ans = func(n);
        cout<<ans<<endl;
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}