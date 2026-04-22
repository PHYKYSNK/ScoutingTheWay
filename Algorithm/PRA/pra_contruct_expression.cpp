/**
 * 构造表达式
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int n = 9;
vector<string> ans;

vector<int> a(n);
vector<char> op(n);

void dfs(int sum,int prev,int x) {
    if(x == n) {
        if(sum == 100) {
            string s = to_string(a[0]);
            for(int j=1;j<n;j++) {
                if(op[j] != ' ') {
                    s += op[j];
                }s += to_string(a[j]); 
            }
            s += "=100";
            ans.emplace_back(s);
        }
    } 
    else {
        op[x] = '+';
        sum += a[x];
        dfs(sum,a[x],x+1);
        sum -= a[x];

        op[x] = '-';
        sum -= a[x];
        dfs(sum,-a[x],x+1);
        sum += a[x];

        op[x] = ' ';
        sum -= prev;
        int t;
        if(prev > 0) t = prev * 10 + a[x];
        else t = prev * 10 - a[x];
        sum += t;
        dfs(sum,t,x+1);
        sum -= t;
        sum += prev;
    }
}
void solve() {
    for(int i=0;i<n;i++) a[i] = i + 1;
    dfs(a[0],a[0],1);
    for(auto& i : ans) {
        cout << i << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}