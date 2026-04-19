#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int binary_search(vector<int>& a,int tar,int l,int r) {
	if(l > r)  return -1;
	int mid = l + (r-l)/2;
	if(a[mid] == tar) return mid;
	if(a[mid] > tar)return binary_search(a,tar,l,mid-1);
	if(a[mid] < tar)return binary_search(a,tar,mid+1,r);
}
void solve(){
	vector<int> a = {1,3,5,7,9,11,13,15,17,19};
	int lena = a.size();
	int tar;cin>>tar;
	cout<<binary_search(a,tar,0,lena-1)-1<<endl;
}

void solve1() {
	vector<int> a = {1,3,5,7,9,11,13,15,17,19};
	int lena = a.size();
	int tar = 11;
	int l=0,r=lena-1;
	int mid;
	while(l<=r) {
		mid = l + (r - l) / 2;
		if(a[mid] == tar) {
			cout<<mid<<endl;
			return ;
		}
		else if(a[mid] < tar) {
			l = mid + 1;
		}
		else {
			r = mid-1;
		}
		
	}
	cout<<-1<<endl;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int _;cin >> _;while(_--)
    solve();
	return 0;
}
