#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct STUDENT{
	string name;
	string id;
	int score;
}student;
bool cmp(const student& s1,const student& s2) {
	// 按照id 升序，按照 score降序  ，应用于挂科之人的筛选 
	if(s1.score == s2.score) {
		return s1.id < s2.id;
	} 
	return s1.score > s2.score;
}
void solve(){
	vector<student> st;
	st.push_back({"ZhangSan", "01", 100});
    st.push_back({"LiSi", "02", 90});
    st.push_back({"WangWu", "03", 100}); // 加一个score相同的案例，验证id升序
    st.push_back({"ZhaoLiu", "00", 85});
	sort(st.begin(),st.end(),[](const student& s1,const student& s2) {
		if(s1.score == s2.score) return s1.id < s2.id;
		return s1.score > s2.score;
	});
	for(auto& i : st) {
		cout<<i.name<<" "<<i.id<<" "<<i.score<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//int _;cin >> _;while(_--)
    solve();
	return 0;
}

