#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

ll func(ll x) {
    if(x == 1) return 1;
    if(x == 2) return 2;
    else return func(x-1) + func(x-2);
}
void solve() {
    ll n;
    while(cin >> n){
        ll ans = func(n);
        cout << ans << endl;
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}