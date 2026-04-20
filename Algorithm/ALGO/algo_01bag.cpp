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
	vector<ll> ans(mc+1,0); //当前重量下能放多少价值的东西。
	for(ll i=0;i<lenw;i++) { // 模拟物品放入。
		if(wei[i] > mc) continue; // 物品太大放不下
		for(ll j=mc;j>=wei[i];j--) { // 更新每个重量放入和不放入的最优值。
									// 倒着循环 ： 因为要用到j - wei[i] 的值
									// 借以二维理解的话，要用到上层的值，正向的话上层的值被覆盖了
			ans[j]=max(ans[j],ans[j-wei[i]] + val[i]);
		} 
	}
	return ans[mc];
}

ll bestvalue2(vector<ll>& wei,vector<ll>& val,ll mc) {
	ll lenw = wei.size();
	ll lenv = val.size();
	vector<vector<ll>> ans(lenw,vector<ll>(mc+1,0));
	for(int i=1;i<lenw;i++) { // 模拟每个物品放入
		if(wei[i] > mc) {     // 物品太大了放不下，此时这个情况等同于上个物品的情况。
			ans[i] = ans[i-1];
			continue;
		} 
		for(ll j=1;j<=mc;j++) { // j循环是模拟背包总重
			if(j < wei[i]) {    // 重量大，归上
				ans[i][j] = ans[i-1][j];
			}
			else {				// 讨论选还是不选，左情况不选，右情况为选，
								// 选的话是上层不带这个物品重量的值（默认最优）
								// 加上自己价值。
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

	//重量
	vector<ll> wei = {0,2,3,4};
	//体积
	vector<ll> val = {0,3,4,5};
	//背包容量
	ll mc = 5;
	//一维dp验证
	cout<< bestvalue1(wei,val,mc)<<endl;
	//二维dp验证
	cout<< bestvalue2(wei,val,mc)<<endl;
	return 0;
}

