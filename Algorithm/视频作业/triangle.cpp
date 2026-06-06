/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    vector<vector<int>> a;
    a.push_back({2});
    a.push_back({3,4});
    a.push_back({6,5,7});
    a.push_back({8,3,9,2});
    int leni = a.size();
    vector<vector<int>> dp = a;
    //先进行初始化
    for(int i=1;i<leni;i++) {
        dp[i][0] += dp[i-1][0];
        dp[i][i] += dp[i-1][i-1];
    }
    for(int i=1;i<leni;i++) {
        for(int j=1;j<i;j++) {
            dp[i][j] += min(dp[i-1][j-1],dp[i-1][j]);
        }
    }

    // for(auto i : dp) {
    //     for(auto j : i) {
    //         cout << j << " ";
    //     }cout << endl;
    // }
    int minsum = INT_MAX;
    int idx = 0;
    for(int i=0;i<leni;i++) {
        if(dp[leni-1][i] < minsum) {
            minsum = dp[leni-1][i];
            idx = i;
        }
    }


    minsum -= a[leni-1][idx];
    vector<int> routine;
    routine.push_back(a[leni-1][idx]);


    for(int i=leni-2;i>=0;i--) {
        
        if(idx > 0 && minsum == dp[i][idx-1]) {
            routine.push_back(a[i][idx-1]);
            idx = idx - 1;
        }
        else(idx > 0 && minsum == dp[i][idx]) {
            routine.push_back(a[i][idx]);
        }
        minsum -= a[i][idx];
    }
    reverse(all(routine));
    for(auto& i : routine) cout << i << " ";
    cout << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}