/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

vector<ll> v;
vector<ll> q;
ll n;

void solve() {
    cin >> n;
    v.resize(n+1);
    q.resize(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        q[i] = q[i-1] + v[i];
    }
    bool pd = false;
    for(int i=1;i<=n;i++) {
        if(q[i-1] == q[n] - q[i]) {
            cout << i-1 << endl;
            pd = true;
            break;
        }
    }
    if(!pd) cout << -1 << endl;
}
int main() {
    solve();
    return 0;
}