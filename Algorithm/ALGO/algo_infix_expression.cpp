#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	int operate1(string op,int num1,int num2) {
		if(op == "+") return num1 + num2;
		else if(op == "-") return num1 - num2;
		else if(op == "*") return num1 * num2;
		else return num2 / num1;	
	}
    int solve(string s) {
    	//优先级，top >= si ，先计算栈。栈绝对优势。 
		map<string,int> pro;
    	pro["*"] = 2;pro["/"] = 2;
    	pro["+"] = 1;pro["-"] = 1;
    	pro["("] = 0;//pro[")"] = 0;
    	
    	int lens = s.size();
		stack<int> num;
		stack<string> op;
		string t = "";
		
		for(int i=0;i<lens;i++) {
			char si = s[i];
			if(si == '(') {
				op.push(string(1,si));
			}
			else if(si == ')') {
				if(!t.empty()) {
					num.push(stoi(t));
					t = "";
				}
				while(op.top() != "(") {
					int num1 = num.top();num.pop();
					int num2 = num.top();num.pop();
					int re = operate1(op.top(),num2,num1);
					num.push(re);
					//这里忘了弹出运算符
					op.pop(); 
				}
				op.pop();//左括号的弹出忘了。 
			}
			else if(isdigit(si)) {
				t += si;
			}
			else {
				//先弹进数字。
				if(!t.empty()) {
					num.push(stoi(t));
					t = "";
				} 
				while(!op.empty() && pro[op.top()] >= pro[string(1,si)]) {
					int num1 = num.top();num.pop();
					int num2 = num.top();num.pop();
					int re = operate1(op.top(),num2,num1);
					num.push(re);
					op.pop();
				}
				op.push(string(1,si));
			}
			
		}
		//压入最后一个数字 
			while(!t.empty()) {
				num.push(stoi(t));
				t = "";
			}
			while(!op.empty()) {
				int num1 = num.top();num.pop();
				int num2 = num.top();num.pop();
				int re = operate1(op.top(),num2,num1);
				num.push(re);
				op.pop();
			}
		return num.top();
    }
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Solution sol;
	cout<<"1+2*3"<<sol.solve("1+2*3")<<endl;
	
	return 0;
}

