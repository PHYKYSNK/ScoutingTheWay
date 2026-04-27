/**
 * 图的广度优先搜索：
 * 给定一个不带权连通图G=(V，E)和一个顶点s，
 * 采用邻接矩阵A存储，利用广度优先搜索方法
 * 求出从顶点s出发到达的每个顶点的最小距离（最小的边数）。
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

/*
    邻接表存元素相邻的元素。
    每个节点都有轨迹，用当前节点，当前路径，当前长度。
    一个队列存当前元素（此元素的路径可以遍历）
    队空即结束。因为每一个元素出队都会有他的所有邻元素入队。
    队不空，每次都出一个元素，用临时变量承接，
    判断他是否为出口，
    出口则输出，
    非出口则继续push
*/

const int N = 20;
int n;
vector<vector<pii>> g(N);
int q,z;


struct node {
    int now;
    vector<int> route;
    int len;
};
void bfs(int start) {
    queue<node> qu;
    node t = {start,{start},1};
    qu.push(t);
    while(!qu.empty()) {
        node cur = qu.front();
        qu.pop();

        int x = cur.now;
        vector<int> rt = cur.route;
        int relen = cur.len;

        if(x == z) {
            cout << "路径长度为 ： " << relen << endl;
            cout << "路程为 ： " ;
            bool jt = false;
            for(auto& i : rt) {
                if(jt) {
                    cout << " -> " << i;
                }
                else {
                    cout << i;
                    jt = true;
                }
            } 
            cout << endl;
            continue;
        }
/**
4
3
1 4
1 3
4 3
1 4
 */
        for(auto& edge : g[x]) {
            bool vis = false;
            for(int i=0;i<rt.size();i++) {
                if(rt[i] == edge.first) {
                    vis = true;
                    break;
                }
            }
            if(vis) continue;
            vector<int> newroute = rt;
            newroute.push_back(edge.first);
            qu.push({edge.first,newroute,relen+edge.second});
        }
    }
}
void solve() {
    cout << "请输入节点数 ： ";cin >> n;
    cout << "请输入边的数 ： ";int tcnt;cin >> tcnt;
    for(int i=0;i<tcnt;i++) {
        cout << "请输入边的端点和权重（此时默认为 1） ： ";
        int a,b,w;
        cin >> a >> b;w = 1;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    cout << "请输入起点和终点 ： ";
    cin >> q >> z;
    bfs(q);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}