/**
 * 求幂集：有一个含n个不同整数的数组a，设计一个算法求其所有子集（幂集）。

   例如，a={1，2，3}
   所有子集是{{1，2，3}，{1，2}，{1，3}，{1}，{2，3}，{2}，{3}，{}}（输出顺序无关）。
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 1e2 + 10;
vector<bool> t(N);
int n;

void dfs(int x) {
    if(x == n) {
        cout << "{";
        bool comma = false;
        for(int i=1;i<=n;i++) {
            if(comma) cout<<",";
            if(t[i]) {
                comma = true;
                cout<<i;
            }
        }cout << "}" << endl;
        return ;
    }
    t[x] = true;dfs(x+1);
    t[x] = false;dfs(x+1);
}
void solve() {
    cout << "输入元素的个数 ： ";
    cin>>n;
    dfs(1);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}