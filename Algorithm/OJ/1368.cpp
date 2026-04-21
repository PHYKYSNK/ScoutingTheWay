#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 210;
vector<ll> par(N,0);
vector<ll> wei(N,0);
void init(int n) {
    for(int i=0;i<n;i++) {
        par[i] = i;
        wei[i] = 1;
    }
}
int findd(int x) {
    if(par[x] == x) return x;
    else return par[x] = findd(par[x]); 
}
void unionbywei(int i,int j) {
    int ri = findd(i);
    int rj = findd(j);
    if(ri != rj) {
        if(wei[ri] > wei[rj]) {
            par[rj] = ri;
            wei[ri] += wei[rj];
        }
        else {
            par[ri] = rj;
            wei[rj] += wei[ri];
        }
    }
}
void solve() {
    int n;cin>>n;
    init(n+1);
    int t;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>t;
            if(t == 1) unionbywei(i,j);
        }
    }
    set<int> stu;
    for(int i=0;i<n;i++) {
        stu.insert(par[i]);
    }
    cout<<stu.size()<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}