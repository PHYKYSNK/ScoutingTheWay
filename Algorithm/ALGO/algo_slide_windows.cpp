#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//idx  0  1  2  3  4  5  6  7 
//     1  3 -1 -3  5  3  6  7
//                    --------                 
//z    5 6 7
//ansz 2 3 3 3 5 5


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<int> ori(n,0);
	for(int i=0;i<n;i++) cin>>ori[i];
	//z是滑动窗口，存储的是ori的偏移量。
	deque<int> z;
	//ansz是最后输出的结果，是在k个长度范围内的结果值。
	vector<int> ansz;
	for(int i=0;i<n;i++) {
		//z不空且当前值小于窗口的最，滑动窗口排,借以使窗口最左元素最大。  由此看出这里求的是最小。
		while(!z.empty() && ori[i] < ori[z.back()]) {
			z.pop_back();
		}
		//窗口加上自己
		z.push_back(i);
		//z不空且窗口超数就扔出。
		while(!z.empty() && z.front() < i-k+1) {
			z.pop_front();
		}
		//符合情况输出窗口的最大。
		if(i >= k - 1) {
			ansz.emplace_back(ori[z.front()]);
		}
	}
	for(auto& i : ansz) cout<<i<<" ";
	cout<<endl;
	
	
	deque<int> j;
	vector<int> ansj;
	for(int i=0;i<n;i++) {
		while(!j.empty() && ori[i] > ori[j.back()]) {
			j.pop_back();
		}
		j.push_back(i);
		while(!j.empty() && z.front() < i - k + 1) {
			j.pop_front();
		}
		if(i > k - 1) {
			ansj.emplace_back(ori[j.front()]);
		}
	}
	cout << "���Ԫ�����У�" <<endl;
	for(auto& i : ansj) cout << i << " ";
	cout << endl;  
	return 0;
}

