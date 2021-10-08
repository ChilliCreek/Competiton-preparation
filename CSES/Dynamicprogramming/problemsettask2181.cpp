//https://cses.fi/problemset/task/2181
#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long
int n, m;

vector<vector<ll>> dp;

void picker(ll pos, ll column, ll subsetAfter, ll subset){
	if(pos == n + 1){
		dp[column + 1][subsetAfter] += dp[column][subset];
		dp[column + 1][subsetAfter] %= MOD;
		return;
	}
	if(subset & (1 << pos - 1)){
		picker(pos + 1, column, subsetAfter, subset);
		return;
	}
	//subset does not need to be changed because pos only goes up
	if(pos + 1 <= n && !(subset & (1 << pos))){
		picker(pos + 2, column, subsetAfter, subset);
	}
	
	
	if(column + 1 <= m){
		picker(pos + 1, column, subsetAfter ^ (1 << pos - 1), subset);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	vector<vector<ll>> DP(m + 1, vector<ll>(1 << n, 0));
	DP[0][0] = 1;
	dp = DP;
	
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < (1 << n); j++){
			picker(1, i, 0, j);
		}
	}
	cout << dp[m][0];
}
