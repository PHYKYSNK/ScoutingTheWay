#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

bool cmp(pii a,pii b) {
    return a.first < b.first;
}
void solve() {
    vector<pii> a;
    a.push_back(make_pair(1,3));
    a.push_back(make_pair(2,6));
    a.push_back(make_pair(8,10));
    a.push_back(make_pair(15,18));
    sort(all(a),cmp);
    vector<pii> re;
    pii t = a[0];
    for(int i=1;i<a.size();i++) {
        if(a[i].first > t.second)  {
            re.push_back(t);
            t = a[i];
        } else {
            t.second = max(t.second,a[i].second);
        }
    }
    re.push_back(t);
    for(auto& i : re) cout << i.first << " " << i.second << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}