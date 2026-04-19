#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

mc 5
wei 2 3 4
val 3 4 5

*/




ll bestvalue1(vector<ll>& wei,vector<ll>& val,ll mc) {
	ll lenw = wei.size();
	ll lenv = val.size();
	vector<ll> ans(mc+1,0);
	for(ll i=0;i<lenw;i++) { // 模拟每一个东西 
		if(wei[i] > mc) continue;
		for(ll j=mc;j>=wei[i];j--) {
			ans[j]=max(ans[j],ans[j-wei[i]] + val[i]);
		} 
	}
	return ans[mc];
}

ll bestvalue2(vector<ll>& wei,vector<ll>& val,ll mc) {
	ll lenw = wei.size();
	ll lenv = val.size();
	vector<vector<ll>> ans(lenw,vector<ll>(mc+1,0));
	for(int i=1;i<lenw;i++) {
		if(wei[i] > mc) {
			ans[i] = ans[i-1];
			continue;
		} 
		for(ll j=1;j<=mc;j++) {
			if(j < wei[i]) {
				ans[i][j] = ans[i-1][j];
			}
			else {
				ans[i][j] = max(
				ans[i-1][j],ans[i-1][j-wei[i]]+val[i]
				);
			}
		}
	}
	return ans[lenw-1][mc];
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int _;cin >> _;while(_--)
//    solve();
	vector<ll> wei = {0,2,3,4};
	vector<ll> val = {0,3,4,5};
	ll mc = 5;
	cout<< bestvalue1(wei,val,mc)<<endl;
	cout<< bestvalue2(wei,val,mc)<<endl;
	return 0;
}

