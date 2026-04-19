#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 1e3+10;
vector<vector<int>> chs(N,vector<int>(N)); 
int idx = 1;
int len;
int sx,sy;//特殊字符位置
//           z为特殊         p为棋盘左上角 
void check(int z1,int z2,int p1,int p2,int size) {
	if(size == 1) return ;
	int s = size / 2;
	int t = idx++;
	int midx = p1 + s,midy = p2 + s;
	//左上
	if(z1 < midx && z2 < midy) {
		check(z1,z2,p1,p2,s);
	} 
	else {
		chs[midx-1][midy-1] = t;
		check(midx-1,midy-1,p1,p2,s);
	}
	//右上 
	if(z1 < midx && z2 >= midy) {
		check(z1,z2,p1,midy,s);
	}
	else {
		chs[midx-1][midy] = t;
		check(midx-1,midy,midx,midy+s,s); 
	}
	//左下 
	if(z1 >= midx && z2 < midy){
		check(z1,z2,midx,p2,s);
	}
	else {
		chs[midx][midy-1] = t;
		check(midx,midy-1,midx,p2,s);
	}
	//右下
	if(z1 >= midx && z2 >= midy) {
		check(z1,z2,midx,midy,s);
	} 
	else {
		chs[midx][midy] = t;
		check(midx,midy,midx,midy,s);
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;cin>>k;
	len = 1 << k;
	cin >> sx >> sy;
	
	idx = 1;
	check(sx,sy,0,0,len);
	
	for(int i=0;i<len;i++) {
		for(int j=0;j<len;j++) {
			cout<<chs[i][j]<<"    ";
		}cout<<endl;
	}
	return 0;
}

