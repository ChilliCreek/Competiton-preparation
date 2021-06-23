//https://codeforces.com/contest/1520/problem/B
#include<bits/stdc++.h>
using namespace std;
#define LOG(x) cout << x << endl


long long main(){
	long long t, n;
	cin >> t;
	long long divisor = 1;
	for(long long j = 0; j < t; j++){
		cin >> n;
		if(n == 1){
			LOG(1);continue;
		}
		else if(n == 2){
			LOG(-1);continue;
		}
		long long matrix[n][n];
		long long rem = 1;
		long long offset = 0;
		for(long long rem = 1; rem <=n; rem ++){
			for(long long start = 0; start < n; start++){
				matrix[rem - 1][(start + offset)%n] = rem + start * n;
			}
			offset++;
		}
		
		for(long long i = 0; i < n; i++){
			for(long long p = 0; p < n; p++){
				cout << matrix[i][p] << " ";
			}
			cout << endl;
		}
	}
}
