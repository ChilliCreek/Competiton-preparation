#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long

int dp[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	int arr[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	dp[0] = 1;
	
	sort(arr, arr + n);
	
	for(int i = 1; i <= x; i++){
		dp[i] = 0;
		int j = 0;
		while(arr[j] <= i && j < n){
			dp[i] += dp[i - arr[j]];
			j++;
			dp[i] %= MOD;
		}
	}
	if(dp[x] == INT_MAX){
		cout << "-1";
	}
	else{
		cout << dp[x];
	}
	
}
