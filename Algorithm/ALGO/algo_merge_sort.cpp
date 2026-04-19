#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> a(N);
vector<int> t(N);

void merge(int l,int mid,int r) {
	int i = l,j = mid+1,k = 0;
	while(i<=mid && j <= r) {
		if(a[i] <= a[j]) t[k++] = a[i++];
		else t[k++] = a[j++]; 
	}	
	while(i <= mid) t[k++] = a[i++];
	while(j <= r) t[k++] = a[j++];
	//ºÏ²¢¹éÎ»
	for(i=l,k=0;i<=r;i++,k++) a[i] = t[k];
}

void merge_sort(int l,int r) {
	if(l >= r) return ;
	int mid = l+(r-l)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,mid,r);
} 

int main() {
	int n;cin>>n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	merge_sort(0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	return 0; 
} 
