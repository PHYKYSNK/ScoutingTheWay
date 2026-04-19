#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

void solve(){
	/*
	n == 3
	pow(2,n) == 8(°üº¬¿Õ¼¯£©
	000      -> 0
	001      -> 1
	010      -> 2
	011      -> 1,2
	
	
	n == 3   
	 1   2   3 
	{}
	{} {1}
	{} {1} {2} {1,2}
	{} {1} {2} {1,2} {3} {2,3} {1,2,3}
	*/
	int n;cin>>n;
	vector<vector<int>> ps;
	vector<int> e;
	ps.emplace_back(e);
	for(int i=1;i<=n;i++) {
		int m = ps.size();
		for(int j=0;j<m;j++) {
			vector<int> e = ps[j];
			e.emplace_back(i);
			ps.emplace_back(e);
		}
	} 
	for(auto& i : ps) {
		for(auto& j : i) {
			cout<<j<<" ";
		}cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int _;cin >> _;while(_--)
    solve();
	return 0;
}

