#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
vector<int> par(N,0);
vector<int> hei(N,1);
vector<int> sum(N,1);
void init(int n) {
	for(int i=0;i<n;i++) {
		par[i] = i;
		hei[i] = 1;
		sum[i] = 1;
	}
}
int findd(int x) {
	if(x == par[x]) return x;
	return par[x] = findd(par[x]);
}
void unionbyhei(int x,int y) {
	int rx = findd(x);
	int ry = findd(y);
	if(rx != ry) {
		if(hei[rx] > hei[ry]) {par[ry] = rx;}
		else if(hei[rx] == hei[ry]) {
			hei[rx]++;
			par[ry] = rx;
		}
		else {par[rx] = ry;}
	} 
}
void unionbysum(int x,int y) {
	int rx = findd(x);
	int ry = findd(y);
	if(rx != ry) {
		if(sum[rx] > sum[ry]) {
			par[ry] = rx;
			sum[rx] += sum[ry];
		}
		else {
			par[rx] = y;
			sum[ry] += sum[rx];
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	/*
	题目描述：一个小岛，输入一个二维数组表示地形
	1 为陆地，0 为海洋
	问有多少个独立的岛屿
	
	思路：将二维数组转换成一维的长数组，
	双层for循环遍历每个土地块，检查他的右一块和下一块
	如果是土地块就给合并
	
	遍历结束后再遍历找有多少个根节点 
	*/ 
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> g[i][j];
		}
	} 
	int total = n * m;
	init(total);
	
	int dx[] = {0,1};
	int dy[] = {1,0};
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(g[i][j] == 1) {
				for(int k=0;k<2;k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(ni < n && nj < m && g[ni][nj] == 1) {
						int u = i * m + j;
						int v = ni * m + nj;
						unionbyhei(u,v); 
					}
				
				}
			}
		}
	}
	
	unordered_set<int> roots;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(g[i][j] == 1) {
				int u = i * m + j;
				roots.insert(findd(u));
			}
		}
	}
	cout<<"岛屿数量 ： " << roots.size() << endl;
	return 0;
}

