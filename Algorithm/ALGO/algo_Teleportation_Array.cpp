/**
 * 迷宫，走迷宫，找到最短路径出去。
 * 传送门问题（LintCode750★★）。
 * 某一天Chell掉进了一个迷宫maze，
 * 迷宫可以看作是一个大小为n×m（
 * 1≤n，m≤200）二维字符数组。
 * 
 * S 入口
 * * 可经过
 * # 墙
 * E 出口
 * 至少多久出迷宫
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 20;
int n;
//默认都是墙
vector<vector<char>> g(N,vector<char>(N,'#'));
pii q,z;
vector<vector<pii>> res;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct node {
    pii now;
    vector<pii> route;
    int len;
};
bool legal(pii x) {
    if(x.first>=n || x.first < 0 || x.second >= n || x.second < 0 || g[x.first][x.second] == '#') return false;
    return true;
}
void bfs(pii start) {
    queue<node> qu;
    node t = {start,{start},1};
    qu.push(t);

    while(!qu.empty()) {
        node cur = qu.front();
        qu.pop();
        pii no = cur.now;
        vector<pii> rou = cur.route;
        int le = cur.len;

        if(no == z) {
            res.push_back(rou);
            continue;
        }
        for(int i=0;i<4;i++) {
            pii tar = {cur.now.first+dx[i],cur.now.second+dy[i]};
            if(legal(tar)) {
                //位置合法还要判断走没走过
                bool vis = false;
                for(auto& j : rou) {
                    if(j == tar){
                        vis = true;
                        break;
                    }
                }
                if(!vis) {
                    vector<pii> newroute = rou;
                    newroute.push_back(tar);
                    qu.push({tar,newroute,le+1});
                }
            }
        }
    }
}

void solve() {
    cout << "请输入迷宫的大小 ： ";
    cin >> n;
    cout << "请输入迷宫的结构（S：入口、E：出口、#：墙、*：路）";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> g[i][j];
            if(g[i][j] == 'S') {
                q = {i,j};
            }
            if(g[i][j] == 'E') {
                z = {i,j};
            }
        }
    }
    bfs(q);
    int numOfSolution = res.size();
    if(numOfSolution == 0) {
        cout << "没有找到路径！" << endl;
        return ;
    }
    for(int i=0;i<numOfSolution;i++) {
        cout << "长度为 ： " << res[i].size();
        cout << "具体路径为 ： ";
        for(auto& j : res[i]) {
            cout << " { " << j.first+1 << "," << j.second+1 << " } ";
        }cout << endl;
    }
}
/*
S###
***#
##*#
##*E
*/
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}