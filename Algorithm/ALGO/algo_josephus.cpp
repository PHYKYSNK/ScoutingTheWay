#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
*用队列模拟
队列先按照顺序放入小孩，创建一个vector接收答案
用出队模拟报数，用一个cnt代表次数，cnt ！= m时
出队再进队，反之则不进队进vector
知道队列.size()为0 停止，输出vector，就是答案 
**/
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	queue<int> q;
	vector<int> ans;
	for(int i=1;i<=n;i++) {
		q.push(i);
	} 
	int cnt = 0;
	while(q.size()  != 0) {
		int t = q.front();
		cnt++;
		q.pop();
		if(cnt == m) {
			ans.emplace_back(t); 
			cnt = 0;
		}
		else {
			q.push(t);
		}
	}
	for(auto& i : ans) cout<<i<<" ";
	cout<<endl;
	return 0;
}

