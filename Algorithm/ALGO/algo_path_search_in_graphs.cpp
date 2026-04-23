/**
 * 图的路径搜索。
 * 给定一个含n个顶点的带权无向图以及图中两个顶点s和t，
 * 设计一个算法求s到t的所有路径及其路径长度。
 */

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 20;
int n;
// 起点 -> 终点 -> 权重。
vector<vector<pii>> g(N);
vector<bool> vis(N);
int relen = 0;
vector<int> route;
int q,z;

void dfs(int x) {
    if(x == z) {
        cout << "此条路径长度为 ： " << relen << "它的总路线为 ： ";
        bool pt = false;
        //cout << q << "->";
        for(auto& i : route) {
            if(pt) cout << "->";
            cout << i;
            pt = true;
        }cout << endl;
        return ;
    }
    for(auto& edge : g[x]) {
        int to = edge.first;
        int w = edge.second;
        if(!vis[to]) {
            vis[to] = true;
            relen += w;
            route.push_back(to);
            dfs(to);
            route.pop_back();
            relen -= w;
            vis[to] = false;
        }
    }
    // for(int i=1;i<=N;i++) {
    //     if(!vis[i]) {
    //         for(auto& j : g[i]) {
    //             relen += j.second;
    //             vis[i] = true;
    //             route.emplace_back(i);
    //             route.pop_back();
    //             vis[i] = false;
    //             relen -= j.second;
    //         }
    //     }
    // }
}
void solve() {
    cout << "请输入节点数 ： ";  
    cin>>n;
    //假设就是1 ~ n这几个节点。
    cout<<"请输入边数 ： ";
    int tcnt;cin >> tcnt;
    int ta,tb,tl;
    for(int i=0;i<tcnt;i++) {
        cout<<"请输入两个点和权重 ： ";
        cin>>ta>>tb>>tl;
        g[ta].push_back(make_pair(tb,tl));
        g[tb].push_back(make_pair(ta,tl));
    }
    cout << "边数已录入！ 请输入起点和终点 ： " << endl;
    cin >> q >> z;
    route.push_back(q);
    vis[q] = true;
    dfs(q);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}