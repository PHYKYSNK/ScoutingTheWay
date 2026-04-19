#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
	阶乘结果末尾的0由10而来
	10 == 2 * 5
	在一个数的分解中，2比5多，所以找5以及5的pow的个数
10 2 
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25
n == 25  5
n == 5   1
*/
ll countlastzero(ll n) {
	if(n < 5) return 0;
	else return n/5 + countlastzero(n/5); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int _;cin >> _;while(_--)
    //solve();
	cout<<countlastzero(11)<<endl;
	cout<<countlastzero(5)<<endl;
	return 0;
}

