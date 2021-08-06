#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long
ll dp[1000002][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t, n;
	cin >> t;
	
	for(int p = 0; p < t; p++){
		cin >> n;
		dp[n][0] = 1;
		dp[n][1] = 1;
		for(int i = n - 1; i > 0; i--){
			dp[i][0] = (dp[i + 1][1] + dp[i + 1][0] + dp[i + 1][0] + 2 * dp[i + 1][0]) % MOD;
			dp[i][1] = (dp[i + 1][1] + dp[i + 1][0] + dp[i + 1][1]) % MOD;
		}
		cout << (dp[1][0] + dp[1][1]) % MOD << endl;
	}
	
	
}
