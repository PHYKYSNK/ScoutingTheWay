#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve() {
    string s;
    getline(cin,s);
    s = " " + s + " ";
    int lens = s.size();
    int ans = 0;
    for(int i=1;i<lens;i++) {
        if(s[i] != ' ' && s[i-1] == ' ') ans++;
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}