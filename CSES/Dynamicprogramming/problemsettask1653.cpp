#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	int people[n];
	
	for(int p = 0; p < n; p++){
		cin >> people[p];
	}
	
	pair<int, int> dp[1<<n];
	dp[0] = make_pair(1, 0);
	for(int i = 1; i < (1 << n); i++){
		dp[i] = make_pair(n + 1, 0);
		for(int j = 0; j < n; j++){
			if(i&(1<<j)){
				pair<int, int> subset = dp[i^(1<<j)];
				if(subset.second + people[j] <= x){
					subset.second += people[j];
				}
				else{
					subset.first++;
					subset.second = people[j];
				}
				dp[i] = min(dp[i], subset);
			}
		}
	}
	cout << dp[(1 << n) - 1].first;
}
