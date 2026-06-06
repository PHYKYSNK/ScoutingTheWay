/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n;cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(i != 0) dp[i] = max(a[i],dp[i-1]+a[i]);
        else {
            dp[i] = a[i];
        }
    }
    cout << *max_element(all(dp)) << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}