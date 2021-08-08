#include<iostream>
#include<vector>
#include<set>
#include<sstream>

using namespace std;
#define MOD 1000000007
#define INT_MAX 2147483647
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, sum;
    cin >> n;
    vector<int> coins(n + 1);

    for(int i = 1 ; i <= n; i++){
        cin >> coins[i];
        sum += coins[i];
    }

    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
    
    for(int i = 1 ; i <= n; i++){
        cin >> coins[i];
        for(int j = 0; j <= sum; j++){
            if(dp[i - 1][j]){
                dp[i][j] = true;
            }
        }
        for(int j = coins[i]; j <= sum; j++){
            if(dp[i - 1][j - coins[i]]){
                dp[i][j] = true;
            }
        }
    }

    stringstream ss;
    int ansNum = 0;
    for(int i = 1; i <= sum; i++){
        if(dp[n][i]){
            ansNum++;
            ss << i << " ";
        }
    }
    cout << ansNum << '\n' << ss.str();
}