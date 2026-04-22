/**
 * 图的m着色问题。给定一个连通图G和m种不同的颜色。
 * 用这些颜色为图G的各顶点着色，每个顶点着一种颜色。
 * 如果有一种着色法使G中每条边的两个顶点着不同颜色，则称这个图是m可着色的。
 * 图的m着色问题是给定图G和m种颜色，找出所有不同的着色方案数。
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 10;
int n,m,b;
int ans = 0;
vector<int> col(N,-1);
vector<vector<int>> a(N);//存i的邻居。

void dfs(int x) {
    if(x > n) {
        ans++;
        return ;
    }
    else {
        for(int i=0;i<m;i++) {
            bool pd = true;
            for(auto& j :a[x]) {
                if(col[j] == i) {
                    pd = false;
                    break;
                }
            }
            if(pd) {
                col[x] = i;
                dfs(x+1);
                col[x] = -1;
            }
        }

    }
}
void solve() {
    cout<<"请输入图的顶点数 ： ";
    cin >> n;
    cout<<"请输入颜色总数 ： ";
    cin >> m;
    cout<<"请输入边的个数 ： ";
    cin >> b;
    int tl,tr;
    for(int i=0;i<b;i++) {
        cout<<"请输入边 ： ";
        cin>>tl>>tr;
        a[tl].emplace_back(tr);
        a[tr].emplace_back(tl);
    }
    dfs(1);
    cout<<ans<<endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}