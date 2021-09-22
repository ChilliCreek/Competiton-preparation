//https://cses.fi/problemset/task/2183
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, sum = 0, med, ans = 1;
	cin >> n;
	ll arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++){
		if(arr[i] > ans){
			break;
		}
		else{
			ans += arr[i];
		}
	}
	
	
	cout << ans;
}
