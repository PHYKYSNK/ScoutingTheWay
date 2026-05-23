/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

vector<ll> a;
ll n,k;
ll maxi = 0;
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<n-k+1;i++) {
        bool pd = true;
        for(int q=0;q<k;q++) {
            if(a[i+q] < a[maxi+q]) {
                pd = false;
                break;
            }
            else if(a[i+q] > a[maxi+q]) {
                break;
            }
        }
        if(pd) {
            maxi = i;
        }
    }
    for(int i=maxi;i<=maxi+k-1;i++) cout << a[i] << " ";
    cout << endl;
}
int main() {
    solve();
    return 0;
}