#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int dp[5001][5001];

int main(){
	long long res = 0;
	int lenS, lenT;
	char s[5005], t[5005];
	scanf("%s%s", s + 1, t + 1);
	lenS = strlen(s + 1);
	lenT = strlen(t + 1);
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1; i <= lenS; i++){
		for(int j = 1; j <= lenT; j++){
			if(s[i] == t[j])
				dp[i][j] = (dp[i][j] + 1 + dp[i-1][j-1]) % MOD;
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
		}
	}
	for(int i = 1; i <= lenS; i++){
		res = (res + dp[i][lenT]) % MOD;
	}
	for(int j = 0; j <= lenS; j++){
		for(int i = 0; i <=lenT;i++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << res;
}
