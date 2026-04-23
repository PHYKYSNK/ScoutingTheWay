/**
 * 子集和问题：给定n个不同的正整数集合a=（a0，a1，…，an-1）和一个正整数t，
 * 要求找出a的子集s，使该子集中所有元素的和为t。
   例如，当n=4时，a=（3，1，5，2），t=8，则满足要求的子集s为（3，5）和（1，5，2）。

   eg : 
   4
   8
   3
   1
   5
   2
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define all(x) (x).begin(),(x).end()

const int N = 10;
int tar;
int n;
vector<int> a(N);
vector<int> ans;
int sum = 0;

void dfs(int sum,int i) {
    if(sum == tar) {
        cout << "此种情况为 ： ";
        for(auto& j : ans) cout << j << " ";cout<<endl;
        return ;
    }
    else if(sum > tar || i >= n) {
        return ;
    }
    sum += a[i];
    ans.push_back(a[i]);
    dfs(sum,i+1);
    ans.pop_back();
    sum -= a[i];
    dfs(sum,i+1);
} 
void solve() {
    cout << "请输入集合的容量 ： " ;
    cin >> n;
    cout << "请输入目标和值 ： ";
    cin >> tar;
    for(int i=0;i<n;i++) {
        cout << "请输入集合的元素 ： " ;
        cin >> a[i];
    }
    dfs(sum,0);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //int _;cin>>_;while(_--)
    solve();
    return 0;
}