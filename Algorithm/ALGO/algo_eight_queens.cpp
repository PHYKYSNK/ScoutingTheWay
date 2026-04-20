#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int N = 20;
int mp[N][N];
int n;

bool check(int x,int y) {
	for(int i=0;i<x;i++) {
		if(mp[i][y]) return false;
	}
	for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--) {
		if(mp[i][j]) return false;
	}
	for(int i=x-1,j=y+1;i>=0&&j<n;i--,j++) {
		if(mp[i][j]) return false;
	}
	return true;
}
inline void dfs(int x) {
	if(x == n) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(mp[i][j] == 1) cout<<"+";
				else cout<<"0";
			}
			cout<<endl;
		}
		cout<<"-------------"<<endl;
		return ;
	}
	for(int i=0;i<n;i++) {
		if(check(x,i)) {
			mp[x][i] = 1;
			dfs(x+1);
			mp[x][i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	while(n <= 3) {
		cout<<"������������ڣ����������� ��"<<endl;
		cin>>n;
	}
	dfs(0);   
	//cout<<flush; 
	return 0;
}

