/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    string s1 = "abcde";s1 = " " + s1;
    string s2 = "ace"; s2 = " " + s2;
    int len1 = s1.size();
    int len2 = s2.size();
    
    vector<vector<int>> dp(len1,vector<int>(len2));
    for(int i=1;i<len1;i++) {
        for(int j=1;j<len2;j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[len1-1][len2-1] << endl;
    vector<char> routine;
    int i = len1 - 1,j = len2 - 1;
    while(i > 0 && j > 0) {
        if(s1[i] == s2[j]) {
            routine.push_back(s1[i]);
            i--;j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(all(routine));
    for(auto& i : routine) cout << i << " ";cout << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}