#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<int> a = {3,6,8,4,10};
int l,r,mid;
void solve(int l,int r){
	if(l >= r) return ;
	int mid = a[(l+r)/2];
	int i=l,j=r;
	while(i <= j) {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i<=j) {
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	solve(l,j);
	solve(i,r);
}
void print() {
	for(auto& i : a) cout<<i<<" ";cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int _;cin >> _;while(_--)
	int l = 0,r = a.size()-1;
	cout<<"数组原来为 ： ";print(); 
    solve(l,r);
    cout<<"快排（正序）之后为 ：";print();
	return 0;
}

