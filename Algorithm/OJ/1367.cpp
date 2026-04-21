#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

ll dp[103][103];
ll c(ll n,ll m) {
    if(m == 0) return 1;
    if(m == n) return 1;
    if(m > n) return 0;
    //return c(n-1,m-1) + c(n-1,m); // 选或不选
    if(dp[n][m] != -1) return dp[n][m];
    return dp[n][m] = c(n-1,m-1) + c(n-1,m);
}
void solve() {
    for(int i=0;i<103;i++) {
        for(int j=0;j<103;j++) {
            dp[i][j] = -1;
        }
    }
    ll n,m;cin>>n>>m;
    ll ans = c(n,m);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}