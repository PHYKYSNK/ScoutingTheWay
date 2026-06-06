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
    ll qsum = 0;
    unordered_map<int,int> exist;
    exist[0] = -1;
    for(int i=0;i<n;i++) cin >> a[i];
    //exist[a[0]] = 0;
    for(int i=0;i<n;i++) {
        qsum += a[i];
        if(exist.count(qsum)) {
            cout << exist[qsum] + 1 << " " << i << endl;
            break;
        }
        exist[qsum] = i;
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}