/**
 * 简单装载问题：有n个集装箱要装上一艘载重量为t的轮船，
 * 其中集装箱i（0≤i≤n-1）的重量为wi。不考虑集装箱的体积限制，
 * 现要选出重量和小于等于t并且尽可能重的若干集装箱装上轮船。
   例如，n=5，t=10，w={5，2，6，4，3}时，
   其最佳装载方案有两种即（1，1，0，0，1）和（0，0，1，1，0），
   对应集装箱重量和达到最大值t。

   eg : 
   5
   10
   5 2 6 4 3
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 100;
int n,t;
vector<int> a(N);
vector<vector<int>> dp(N,vector<int>(N,0));
vector<int> path;
//         次序   重量和
void dfs(int i,int j) {
    if(i == 0) {
        reverse(all(path));
        for(auto& j : path) cout<<j<<" ";cout<<endl;
        reverse(all(path));
        return ;
    }
    if(dp[i][j] == dp[i-1][j]) {
        path.emplace_back(0);
        dfs(i-1,j);
        path.pop_back();
    }
    if(j >= a[i] && dp[i][j] == dp[i-1][j-a[i]] + a[i]) {
        path.push_back(1);
        dfs(i-1,j-a[i]);
        path.pop_back();
    }
}
void solve() {
    cout << "请输入集装箱的数量 ： ";
    cin >> n;
    cout << "请输入轮船的载重量 ： ";
    cin >> t;
    cout << "请输入货物的重量 ： ";
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) {
        //int now = a[i];
        // if(now > t) {
        //     dp[i] = dp[i-1];
        //     continue;
        // }
        for(int j=0;j<=t;j++) {
            if(j < a[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]] + a[i]);
        }
    }
    cout<<"最优装载重量 ： ";
    cout<<dp[n][t] << endl;
    cout<<"最优装载方案 ： " << endl;
    dfs(n,t);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}