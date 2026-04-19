#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
//首先这个算法是O(nlogn) ,没有kandane好用 
int maxcrosssum(const vector<int>& a,int l,int r,int mid) {
	int lsum = INT_MIN,rsum = INT_MIN;
	int sum = 0;
	for(int i=mid;i>=l;i--) {
		sum += a[i];
		lsum = max(lsum,sum);
	}
	sum = 0;
	for(int i=mid+1;i<=r;i++) {
		sum += a[i];
		rsum = max(rsum,sum);
	}
	return lsum + rsum;
}
int maxsubsum(const vector<int>& a,int l,int r) {
	if(l == r)  return a[l];
	int mid = l + (r - l) / 2;
	int lsum = maxsubsum(a,l,mid);
	int rsum = maxsubsum(a,mid+1,r);
	int csum = maxcrosssum(a,l,r,mid);
	return max({lsum,rsum,csum});
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int lena = a.size();
	int res = maxsubsum(a,0,lena-1);
	cout<<"最大连续子序列和是："<<res<<endl; 
	return 0;
}

