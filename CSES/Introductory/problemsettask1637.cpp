//https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, i, j;
	cin >> n;
	int dp[n+1];
	dp[0] = 0;
	for(i = 1; i <= n; i++){
		int min = INT_MAX;
		j = i;
		while(j > 0){
			if(dp[i - j%10] < min){
				min = dp[i - j%10];
			}
			j /= 10;
		}
		dp[i] = min + 1;
	}
	
	cout << dp[n];
}
