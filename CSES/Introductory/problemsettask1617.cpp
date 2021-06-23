#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){
	int n, res = 1;
	cin >> n;
	while(n > 0){
		res *= 2;
		res %= MOD;
		n--;
	}
	cout << res;
}
