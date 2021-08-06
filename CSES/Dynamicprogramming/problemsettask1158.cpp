#include<iostream>
#include<vector>

using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	
	
	vector<int> prices(n + 1), pages(n);
	vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
	for(int i = 1; i <= n; i++){
		cin >> prices[i];
	}
	for(int i = 0; i < n; i++){
		cin >> pages[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= x; j++){
			if(i != 0 && j != 0){
				if(prices[i] <= j){
					dp[i][j] = max(dp[i - 1][j], pages[i - 1] + dp[i - 1][j - prices[i]]);
				}
				else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	
	cout << dp[n][x];
}
