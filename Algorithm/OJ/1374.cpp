/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(2*n);
    for(int i=0;i<n*2;i++) {
        cin >> a[i];
    }
    sort(all(a));
    ll re = 0;
    for(int i=0;i<n*2;i+=2) {
        re += a[i];
    }
    cout << re << endl;
}
int main() {
    solve();
    return 0;
}