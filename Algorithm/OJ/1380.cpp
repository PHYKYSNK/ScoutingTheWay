#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    ll n;cin>>n;
    unordered_map<ll,ll> cnt;
    set<ll> exis;
    for(int i=0;i<n;i++) {
        ll t;cin>>t;
        //exis.insert(t);
        cnt[t]++;
    }
    for(auto& i : cnt) {
        if(i.second * 2 > n) {
            cout<<i.first<<endl;
            return ;
        } 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}