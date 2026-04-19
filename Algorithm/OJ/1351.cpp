#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(all(a),[](int a,int b) {
        return a > b;
    });
    cout << a[k-1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}