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
    int count = 1;
    int end = a[0].second;
    for(int i=1;i<lena;i++) {
        int start = a[i].first;
        if(start >= end) {
            count++;
            end = a[i].second;
        }
    }
    cout << lena - count << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}