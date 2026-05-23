/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

ll n,k;
vector<ll> cars;
//vector<ll> q;

void solve() {
    cin >> n >> k;
    cars.resize(n);
    //q.resize(n+1);
    for(int i=0;i<n;i++) {
        cin >> cars[i];
        //q[i] = q[i-1] + cars[i];
    }
    ll re = LLONG_MAX;
    sort(all(cars));
    for(int i=0;i<=n-k;i++) {
        re = min(re,cars[i+k-1]-cars[i]+1);
    }
    cout << re << endl;
}
int main() {
    solve();
    return 0;
}