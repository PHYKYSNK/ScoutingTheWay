#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    string s;cin>>s;
    stack<char> sc;
    int lens = s.size();
    if(lens <= 1) {
        cout<<"false";
        return ;
    }
    bool pd = true;
    for(int i=0;i<lens;i++) {
        char r = s[i];
        if(r == ')') {
            if(sc.empty()) {
                pd = false;
                break;
            }
            if(sc.top() != '(') {
                pd = false;
                break;
            }
            else sc.pop();
        }
        else if(r == ']') {
            if(sc.empty()) {
                pd = false;
                break;
            }
            if(sc.top() != '[') {
                pd = false;
                break;
            }
            else sc.pop();
        }
        else if(r == '}') {
            if(sc.empty()) {
                pd = false;
                break;
            }
            if(sc.top() != '{') {
                pd = false;
                break;
            }
            else sc.pop();
        }
        else {
            sc.push(r);
        }
    }
    if(pd) cout<<"true";
    else cout<<"false";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}