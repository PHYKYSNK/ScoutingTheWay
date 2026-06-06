/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

bool cmp(pii a,pii b) {
    return a.second < b.second;
}

void solve() {
    vector<pii> a;
    a.push_back({1,2});
    a.push_back({2,3});
    a.push_back({3,4});
    a.push_back({1,3});

    int lena = a.size();
    sort(all(a));
    vector<pii> re;
    re.push_back(a[0]);
    int end = a[0].second;
    for(int i=1;i<lena;i++) {
        if(a[i].first >= end) {
            re.push_back(a[i]);
            end = a[i].second;
        }
    }
    cout << a.size() << endl;
    for(auto& i : re) {
        cout << i.first << " " << i.second << endl;
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}