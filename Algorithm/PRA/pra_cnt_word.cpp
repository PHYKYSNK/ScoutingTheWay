#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int countSegments(string& s) {
	int ans = 0;
	string s1 = " " + s + " ";
	cout<<1<<s1<<1<<endl;
	int lens1 = s1.size();
	for(int i=0;i<lens1-1;i++) {
		if(s1[i] == ' ' && s1[i+1] != ' ') {
			ans ++;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;getline(cin,s);
	cout<<countSegments(s);
	return 0;
}

