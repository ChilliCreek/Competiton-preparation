//https://cses.fi/problemset/task/1639
#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string first, second;
	cin >> first >> second;
	
	int len1 = first.length(), len2 = second.length();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	
	for(int i = 0; i <= len1; i++){
		dp[i][0] = i;
	}
	
	for(int i = 0; i <= len2; i++){
		dp[0][i] = i;
	}
	
	
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			int cost = (first[i - 1] == second[j - 1]) ? 0 : 1;
			dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + cost);
		}
	}
	
	cout << dp[len1][len2];
}
