//https://cses.fi/problemset/task/1744
#include<iostream>
#include<vector>

using namespace std;
#define MOD 1000000007
#define INT_MAX 2147483647
#define ll long long

vector<vector<int> > dp;

void solve(int n, int m){
    if(n == m){
        dp[n][m] = 0;
        return;
    }
    int minimum = INT_MAX;
    for(int i = 1; i < n; i++){
        if(dp[i][m] == -1)solve(i, m);
        if(dp[n - i][m] == -1)solve(n - i, m);
        if(minimum > dp[i][m] + dp[n - i][m] + 1){
            minimum = dp[i][m] + dp[n - i][m] + 1;
        }
    }
    for(int j = 1; j < m; j++){
        if(dp[n][j] == -1)solve(n, j);
        if(dp[n][m - j] == -1)solve(n, m - j);
        if(minimum > dp[n][j] + dp[n][m - j] + 1){
            minimum = dp[n][j] + dp[n][m - j] + 1;
        } 
    }
    dp[n][m] = minimum;
    dp[m][n] = minimum; 
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int a, b;
    cin >> a >> b;
    int c = a > b ? a : b;
    vector<vector<int> > DP(c + 1, vector<int>(c + 1, -1));
    dp = DP;

    solve(a, b);
    cout << dp[a][b] << '\n';
}
