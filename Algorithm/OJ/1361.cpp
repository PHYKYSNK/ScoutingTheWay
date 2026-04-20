#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n;cin>>n;
    ll ans = 0;
    ll t = 5;
    while(n >= t) {
        ans += n / t;
        t *= 5;
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}