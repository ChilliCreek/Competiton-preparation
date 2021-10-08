//https://cses.fi/problemset/task/1074
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, sum = 0, med, ans = 0;
	cin >> n;
	ll arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	if(n % 2 == 0){
		med = (arr[n / 2] + arr[n / 2 -1]) / 2;
	}
	else{
		med = arr[n / 2];
	}
	for(int i = 0; i < n; i++){
		ans += abs(arr[i] - med);
	}
	cout << ans;
}
