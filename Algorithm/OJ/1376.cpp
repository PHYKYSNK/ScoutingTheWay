/**
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    multiset<string> a;
    //奇数
    for(int i=0;i<n;i++) {
        int j=i,k=i;
        while(j >= 0 && k < n) {
            if(s[j] == s[k]) {
                a.insert(s.substr(j,(i-j)*2+1));
                j--;k++;
            }
            else {
                break;
            }
        }
    }
    //偶数
    for(int i=0;i<n;i++) {
        int j=i,k=i+1;
        while(j >= 0 && k < n) {
            if(s[j] == s[k]) {
                a.insert(s.substr(j,(i-j+1)*2));
                j--;k++;
            }
            else break;
        }
    }
    //for(auto& i : a) cout << i << endl;
    cout << a.size() << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}