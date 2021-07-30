#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long
vector<int> digits;
ll sizee, a, b;

void digitize(ll num){
	digits.clear();
	if(num <= 0){
		digits.push_back(0);
		sizee = 1;
		return;
	}
	int index = 0;
	while(num > 0){
		digits.push_back(num % 10);
		num /= 10;
		index++;
	}
	reverse(digits.begin(), digits.end());
	sizee = index;
}

ll dp[20][10][2][2];

ll solve(int index, int notAllowed, bool zerosEnabled, bool notLow){
	//base case
	if(index == sizee){
		return 1;
	}
	//Memoization
	if(notAllowed != -1 && dp[index][notAllowed][zerosEnabled][notLow] > -1){
		return dp[index][notAllowed][zerosEnabled][notLow];
	}
	
	int upperLimit = 9;
	if(notLow){
		upperLimit = digits[index];
	}
	
	ll res = 0;
	for(int i = 0; i <= upperLimit; i++){
		if(i == notAllowed && zerosEnabled == 0){
			continue;
		}
		res += solve(index + 1, i, zerosEnabled && i == 0, notLow && i == upperLimit);
	}
	
	if(notAllowed != -1){
		dp[index][notAllowed][zerosEnabled][notLow] = res;
	}
	return res;
}

void reset(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
			for(int p = 0; p < 2; p++){
				for(int k = 0; k < 2; k++){
					dp[i][j][p][k] = -1;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b;
	
	reset();
	ll res1;
	if(a == 0){
		res1 = 0;
	}
	else{
		digitize(a - 1);
	    res1 = solve(0, -1, true, true);
	}
	reset();
	digitize(b);
	ll res2 = solve(0,- 1, true, true);
	//cout << res2 << endl;
	cout << res2 - res1;
}
