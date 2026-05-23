#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n;cin>>n;
    n = fabs(n);
    bool pd = ( n & (n-1) );
    if(!pd) cout << "true" << endl;
    else cout << "false" << endl;
}
int main() {
    solve();
    return 0;
}