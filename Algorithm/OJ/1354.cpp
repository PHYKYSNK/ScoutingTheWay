#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(string s) {
    int lens = s.size();
    stack<string> str;
    stack<int> num;
    string str1 = "";
    string num1 = "";
    for(int i=0;i<lens;i++) {
        char st = s[i];
        if(isdigit(st)) {
            num1 += st;
        }
        else if(isalpha(st)) {
            str1 += st;
        }
        else if(st == '[') {
            str.push(str1);
            str1 = "";
            num.push(stoi(num1));
            num1 = "";
        }
        else if(st == ']') {
            int rep = num.top();
            num.pop();
            string pre = str.top();
            str.pop();
            string t = "";
            for(int j=0;j<rep;j++) {
                t += str1;
            }
            str1 = pre + t;
        }
    }
    cout<<str1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    string s;
    cin >> s;
    solve(s);
    return 0;
}