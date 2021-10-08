//https://cses.fi/problemset/task/1638
#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long
vector<vector<bool>> paths(1001, vector<bool>(1001, false));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));
vector<vector<int>> dp(1001, vector<int>(1001, 0));

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	char temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> temp;
			if(temp == '*'){
				paths[i][j] = true;
			}
		}
	}
	
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	dp[0][0] = 1;
	
	if(paths[0][0]){
		cout << 0;
	}
	else{
		while(!q.empty()){
			pair<int,int> pos = q.front();
			q.pop();
			
			if(visited[pos.first][pos.second]){
				continue;
			}
			
			if(pos.first + 1 < n && !paths[pos.first + 1][pos.second]){
				dp[pos.first + 1][pos.second] += dp[pos.first][pos.second];
				dp[pos.first + 1][pos.second] %= MOD;
				q.push(make_pair(pos.first + 1, pos.second));
			}
			if(pos.second + 1 < n && !paths[pos.first][pos.second + 1]){
				dp[pos.first][pos.second + 1] += dp[pos.first][pos.second];
				dp[pos.first][pos.second + 1] %= MOD;
				q.push(make_pair(pos.first , pos.second + 1));
			}
			visited[pos.first][pos.second] = true;
		}
		
		
		cout << dp[n - 1][n - 1];
	}
	
}
