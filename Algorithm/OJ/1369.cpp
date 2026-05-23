#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9 + 7;


void solve() {
    ll n,k;
    cin >> n >> k;
    unordered_map<ll,ll> cnt;
    cnt[0] = 1;
    vector<ll> nums(n+1,0);
    vector<ll> q(n+1,0);
    for(int i=1;i<=n;i++) {
        cin >> nums[i];
    }
    ll res = 0;
    for(int i=1;i<=n;i++) {
        q[i] = q[i-1] + nums[i];
        res += cnt[q[i] - k];
        res %= MOD;
        cnt[q[i]]++;
    }
    cout << res << endl;
}
int main() {
    solve();
    return 0;
}