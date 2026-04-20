#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    int n;cin>>n;
    int t;
    bool pd = false;
    unordered_map<int,bool> um;
    for(int i=0;i<n;i++) {
        cin>>t;
        if(um[t] != false) {
            pd = true;
        }
        um[t] = true;
    }
    if(pd) cout<<"true";
    else cout<<"false";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}