//https://cses.fi/problemset/task/1093
#include<iostream>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, sum = 0;
    cin >> n;
    sum = (n + 1) * n / 2;
    ll dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= sum; j++){
            dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= (MOD * 2);
        }
        for(int j = 0; j <= sum; j++){
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= (MOD * 2);
        }
    }
    if(sum % 2 == 0){
        cout << dp[n][sum / 2] / 2;
    }
    else{
        cout << '0';
    }
}
