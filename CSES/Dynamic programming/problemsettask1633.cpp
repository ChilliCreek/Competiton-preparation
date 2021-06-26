#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long

ll dp[1000000] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, sum = 63;
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 8;
	dp[4] = 16;
	dp[5] = 32;
	
	for(int i = 6; i < n; i++){
		dp[i] = sum;
		sum += dp[i] - dp[i - 6];
		sum %= MOD;
	}
	if(dp[n - 1] < 0){
		cout << dp[n - 1] + MOD;
	}
	else{
		cout << dp[n - 1];
	}
}
