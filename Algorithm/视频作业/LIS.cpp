/**
 * 最长递增子序列：给定一个无序的整数序列a[0..n-1]，
 * 求其中最长递增（严格）子序列的长度。
例如，a={2，1，5，3，6，4，8，9，7}，n=9，
其最长递增子序列为{1，3，4，8，9}，结果为5。
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    vector<int> a = {2,1,5,3,6,4,8,9,7};
    int lena = a.size();
    //dp就是以当前数字为末尾的最长的子序列长度
    vector<int> dp(lena,1);
    for(int i=0;i<lena;i++) {
        for(int j=0;j<i;j++) {
            //每轮找到前面的一个小的然后更新。
            if(a[i] > a[j]) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    cout << *max_element(all(dp)) << endl;
}
void solve1() {
    vector<int> a = {2,1,5,3,6,4,8,9,7};
    int lena = a.size();
    vector<int> re;
    for(int i=0;i<lena;i++) {
        auto pos = lower_bound(all(re),a[i]);//位置
        if(pos == re.end()) { // 就是最大的
            re.push_back(a[i]);
        }
        else {
            *pos = a[i];
        }
    }
    cout << re.size() << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    solve1();
    return 0;
}