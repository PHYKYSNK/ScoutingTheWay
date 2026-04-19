#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string decodeString(string s) {
	stack<string> num;
	stack<string> str;
	int lens = s.size();
	string num1 = "";
	string str1 = "";
	for(int i=0;i<lens;i++) {
		if(isdigit(s[i])) {
			num1 += s[i];
		}
		else if(isalpha(s[i])) {
			str1 += s[i];
		}
		else if(s[i] == '[') {
			num.push(num1);
			num1 = "";
			str.push(str1);
			str1 = "";
		}
		/* 
		
		*/
		else if(s[i] == ']') {
			int repeat = stoi(num.top());
			num.pop();
			string pre = str.top();
			str.pop();
			
			string t = "";
			for(int j=0;j<repeat;j++) {
				t += str1;
			}
			str1 = pre + t;
		}
	}
	return str1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	cout<<decodeString(s)<<endl; 
	return 0;
}

