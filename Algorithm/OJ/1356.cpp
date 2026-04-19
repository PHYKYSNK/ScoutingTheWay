#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve() {
    int n;cin>>n;
    multiset<int> s;
    int t;
    for(int i=0;i<n;i++) {
        cin>>t;
        s.insert(t*t);
    }
    for(auto& i : s) cout<<i<<" ";cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}