#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

void dfs1(int x) {
	vector<int> a(x,0);
	for(int i=0;i<x;i++) {
		a[i] = i + 1;
	}
	do {
		for(auto& i : a) cout<<i<<" ";cout<<endl;
	} while(next_permutation(a.begin(),a.end()));
	  //    prev_permutation
}

const int N = 1e3 + 10;
vector<bool> num(N,false); //visitÊý×é 
vector<int> ans(N,0);
int n;

//void init(int n) {
//	for(int i=0;i<=n;i++) {
//		num[i] = true;
//	}
//}
void dfs2(int x) {
	if(x == n) {
		for(int i=0;i<n;i++) {
			cout<<ans[i]<<" ";
		}cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(num[i] == false) {
			ans[x] = i;
			num[i] = true;
			dfs2(x+1);
			num[i] = false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	//dfs1(n);
	
	//init(n);
	dfs2(0);
	return 0;
}

