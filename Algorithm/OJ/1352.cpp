#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> ori(n);
    for(int i=0;i<n;i++) cin >> ori[i];
    deque<ll> wind;
    vector<ll> ansx;//smallest
    for(int i=0;i<n;i++) {
        //先去前
        while(!wind.empty() && ori[i] <= ori[wind.back()]) {
            wind.pop_back();
        }
        //加自己
        wind.push_back(i);
        //去长度
        while(!wind.empty() && wind.front() < i - k + 1) {
            wind.pop_front();
        }
        if(i >= k - 1) {
            ansx.emplace_back(ori[wind.front()]);
        }
    }
    for(auto& i : ansx) cout<<i<<" ";cout<<endl;
    while(!wind.empty()) wind.pop_back();
    vector<ll> ansd;
    for(int i=0;i<n;i++) {
        while(!wind.empty() && ori[i] >= ori[wind.back()]) {
            wind.pop_back();
        }
        wind.push_back(i);
        while(!wind.empty() && wind.front() < i - k + 1) {
            wind.pop_front();
        }
        if(i >= k - 1) {
            ansd.push_back(ori[wind.front()]);
        }
    }
    for(auto& i : ansd) cout<<i<<" ";cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}