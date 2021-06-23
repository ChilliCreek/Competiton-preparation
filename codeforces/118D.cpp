#include<bits/stdc++.h>

using namespace std;

int main(){
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	int dp[n1 + 1][n2 + 1][k1 + 1][k2 + 1];
	memset(dp, 0, sizeof(dp));
	for(int nf = 0; nf <= n1; nf++){
		for(int nh = 0; nh <= n2; nh++){
			for(int kf = 0; kf <= k1; kf++){
				for(int kh = 0; kh <= k2; kh++){
					int& res = dp[nf][nh][kf][kh]; 
					if(nf == 0 && nh == 0){
						res = 1;
					}else{
						if(nf > 0 && kf > 0){
							res += dp[nf - 1][nh][kf - 1][k2];
						}
						res = res % 100000000;
						if(nh > 0 && kh > 0){
							res += dp[nf][nh - 1][k1][kh - 1];
						}
						res = res % 100000000;
					}
				}
			}
		}
	}
	cout << dp[n1][n2][k1][k2];
}
