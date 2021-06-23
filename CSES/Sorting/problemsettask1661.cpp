#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, currSum = 0, inp, ans = 0;
	cin >> n;
	ll arr[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> inp;
		currSum += inp;
		arr[(currSum % n + n) % n]++;
	}
	for(int i = 0; i < n; i++){
		ans += arr[i] * (arr[i] - 1) / 2;
	}
	ans += arr[0];
	cout << ans;
}
