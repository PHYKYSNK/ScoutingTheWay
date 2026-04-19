#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve() {
    string a,b;
    cin>>a>>b;
    unordered_map<char,int> cnta;
    unordered_map<char,int> cntb;
    int lena = a.size();
    int lenb = b.size();
    for(int i=0;i<lena;i++) {
        cnta[a[i]]++;
    }
    for(int i=0;i<lenb;i++) {
        cntb[b[i]]++;
    }
    for(int i=0;i<lenb;i++) {
        char t = b[i];
        if(cnta[t] < cntb[t]) {
            cout<<"false";
            return ;
        }
    }
    cout<<"true";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}