#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//asdfasdfasdfasdffdsafdsafdsafdsaa
//   nbabbabn
int hw(string s) {
	int lens = s.size();
	int ans = 0;
	//单数长度
	for(int i=0;i<lens;i++) {
		int l = i,r = i;
		while((l>=0)&&(r<lens)) {
			if(s[l] == s[r]) ans++;
			else break;
			l--;r++;
		}
	} 
	//双数长度
	for(int i=0;i<lens-1;i++) {
		//if(s[i] == s[i+1]) {
			int l=i,r=i+1;
			while((l>=0)&&(r<lens)) {
				if(s[l]==s[r]) ans++;
				else break;
				l--;r++;
			}
		//}
	} 
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int re = hw(s);
	cout<<re<<endl;
	return 0;
}

