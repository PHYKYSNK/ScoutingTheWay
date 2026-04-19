#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int func1(vector<int>& a) {
	int lena = a.size();
	int ans = a[0],sumt = 0;
	for(int i=0;i<lena;i++) {
		sumt += a[i];
		ans = max(ans,sumt);
		if(sumt < 0) sumt = 0;
	}
	return max(0,ans);
}
int func2(const vector<int> &a){
    int len = a.size();
    int curr = a[0];
    int maxx = curr;
    for(int i=1;i<len;i++){
        curr = max(a[i],curr+a[i]);
        maxx = max(curr,maxx);
    }
    return max(maxx,0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	} 
	cout<<func2(a)<<endl;
	return 0;
}

